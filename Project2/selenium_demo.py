from selenium import webdriver

driver = webdriver.Chrome()

url = "https://www.indeed.com/jobs?q=data+engineer&l=New+York&start=10"
driver.get(url)

driver.implicitly_wait(2)

def get_review_page_hrefs():
    reviewslink_xpath = '//a[contains(@class, "ratingNumber")]'
    links = driver.find_elements_by_xpath(reviewslink_xpath)
    hrefs = []
    for link in links:
        href = link.get_attribute("href")
        hrefs.append(href)
    return hrefs


def get_review_counts(hrefs):
    review_counts = []
    for href in hrefs:
        driver.get(href)
        reviewcount_xpath = '//a[contains(@class, "cmp-RatingsCountLink")]'
        reviewcount_elements = driver.find_elements_by_xpath(reviewcount_xpath)
        for elem in reviewcount_elements:
            review_counts.append((href, elem.text))
            print((href, elem.text))
    return review_counts


if __name__ == "__main__":
    hrefs = get_review_page_hrefs()
    review_counts = get_review_counts(hrefs)

    with open("indeed_review_counts.csv", "w") as f:
        for rc in review_counts:
            f.write(f"{rc[0]}, {rc[1]}\n")
