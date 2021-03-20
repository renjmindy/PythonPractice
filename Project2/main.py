import requests
import pandas as pd
from bs4 import BeautifulSoup as soup
import time
import re

pd.set_option('display.max_columns', None)

def getDataIndeed(job_title, location, url):
    """
        This method scrapes the indeed website for specific job title and location given
        @job_title - current job title being searched, also used to name the file where results are stored
        @location - current location of job title, also used to name the file where results are stored
        @url - current url that is being requested.
    """
    page = requests.get(url)

    bsobj = soup(page.content,'lxml')

    #print(bsobj)

    jobTitle = []
    jobEmployer = []
    jobLocation = []
    jobDescription = []
    jobUrl = []
    jobReviews = []


    for header in bsobj.findAll('h2', {'class':'title'}):
        jobTitle.append(header.text.strip())

    for header in bsobj.findAll('span', {'class':'company'}):
        jobEmployer.append( header.text.strip())

    for header in bsobj.findAll('div', {'class':'location accessible-contrast-color-location'}):
        jobLocation.append(header.text.strip())

    for header in bsobj.findAll('span', {'class':'location accessible-contrast-color-location'}):
        jobLocation.append(header.text.strip())

    for header in bsobj.findAll('div', {'class':'summary'}):
        jobDescription.append(header.text.strip())


    for header in bsobj.findAll('a', {'class': 'jobtitle turnstileLink'}, href=True):
        jobUrl.append(header['href'])

        tempUrl = "https://www.indeed.com" + header['href']
        tempPage = requests.get(tempUrl)
        jobDetail = soup(tempPage.content,'lxml')
        
        reviews = jobDetail.findAll('div', {'class':'icl-Ratings-count'})
        try: 
            jobReviews.append(reviews[0].text.strip())
        except:
            jobReviews.append("No Reviews")

        time.sleep(3)

    print(len(jobReviews))

    jobDetails = {
        'title': jobTitle,
        'employer': jobEmployer,
        'location': jobLocation,
        'description': jobDescription,
        'url': jobUrl,
        'reviews': jobReviews
    }

    df = pd.DataFrame.from_dict(jobDetails)
    print(df)
    df.to_csv(f"indeed-{job_title}-results-{location}.csv", sep=',', index=False)
    return df


def getDataGlassDoor(job_title, location, url):
    """
        This method scrapes the glassdoor website for specific job title and location given
        @job_title - current job title being searched, also used to name the file where results are stored
        @location - current location of job title, also used to name the file where results are stored
        @url - current url that is being requested.
    """

    page = requests.get(url)

    bsobj = soup(page.content,'lxml')

    print(bsobj)

    jobTitle = []
    jobEmployer = []
    jobLocation = []
    jobDescription = []
    jobUrl = []
    jobReviews = []


    for header in bsobj.findAll('a', {'class':'jobLink css-1rd3saf eigr9kq2'}):
        jobTitle.append(header.text.strip())

    for header in bsobj.findAll('a', {'class':' css-l2wjgv e1n63ojh0 jobLink'}):
        jobEmployer.append( header.text.strip())

    for header in bsobj.findAll('div', {'class':'pr-xxsm css-1ndif2q e1rrn5ka0'}):
        jobLocation.append(header.text.strip())

    #for header in bsobj.findAll('span', {'class':'location accessible-contrast-color-location'}):
    #    jobLocation.append(header.text.strip())

    #for header in bsobj.findAll('div', {'class':'summary'}):
    #    jobDescription.append(header.text.strip())

    
    jobDetails = {
        'title': jobTitle,
        'employer': jobEmployer,
        'location': jobLocation
        #'description': jobDescription
        #'url': jobUrl,
        #'reviews': jobReviews
    }

    df = pd.DataFrame.from_dict(jobDetails)
    print(df)
    df.to_csv(f"glassdoor-{job_title}-results-{location}.csv", sep=',', index=False)
    return df


# Data Engineer
#dfDEBoston = getDataIndeed('https://www.indeed.com/jobs?q=Data+Engineer&l=Boston')
#dfDEPortland = getDataIndeed('https://www.indeed.com/jobs?q=Data+Engineer&l=Portland')
#dfDESanDiego = getDataIndeed('https://www.indeed.com/jobs?q=Data+Engineer&l=San+Diego%2C+CA')
#dfDEDallas = getDataIndeed('https://www.indeed.com/jobs?q=Data+Engineer&l=Dallas%2C+TX')
#dfDEDenver = getDataIndeed('https://www.indeed.com/jobs?q=Data+Engineer&l=Denver%2C+CO')
#dfDEHartford = getDataIndeed('https://www.indeed.com/jobs?q=Data+Engineer&l=Hartford%2C+CT')
#dfDEAtlanta = getDataIndeed('https://www.indeed.com/jobs?q=Data+Engineer&l=Atlanta%2C+GA')

# Data Scientist

locations = ['Boston', 'Portland', 'San+Diego', 'Dallas', 'Denver', 'Hartford', 'Altlanta']

jobTitleIndeed = ['Data+Engineer', 'Big+Data+Developer']
for job in jobTitleIndeed:
    for location in locations:
        getDataIndeed(job, location, f'https://www.indeed.com/jobs?q={job}&l={location}')
        time.sleep(3)
    

# Big Data Developer

jobTitleGlassDoor = ['Data%20Scientist', 'Big%20Data%20Developer']
for job in jobTitleGlassDoor:
    for location in locations:
        getDataGlassDoor(job, location, f'https://www.glassdoor.com/Job/jobs.htm?sc.keyword={job}&suggestCount=0&suggestChosen=false&clickSource=searchBox&locId=1154532&locT=C&locName={location}')
        time.sleep(3)
