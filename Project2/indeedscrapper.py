import requests
import pandas as pd
from bs4 import BeautifulSoup as soup

def getDataIndeed(url):
    
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
        
        reviews = jobDetail.find('div', {'class':'icl-Ratings-count'})

        jobReviews.append(reviews)



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
    pd.set_option('display.max_columns', None)
    df.to_csv("results.csv", sep=',')

    return df
