
from bs4 import BeautifulSoup
import requests
import re
from os import path

base_url = "https://house.fandom.com"
root_url = base_url + "/wiki/House_Wiki"

print(root_url)
fp = requests.get(root_url)

def get_seasons(fd):

    soup = BeautifulSoup(fd, 'html.parser')
    epbox = soup.find("div", {"id": "epbox"})
    season_lists = epbox.findAll("ul")
    top_list = season_lists[0]
    seasons_hrefs = [elem["href"] for elem in top_list.findAll("a")]
    return [base_url + season_href for season_href in seasons_hrefs]

def get_html_file_name(link):
    return link.split("/")[-1] + ".html"

def save_season(link):
    print("Saving season: {}".format(get_html_file_name(link)))
    fp = requests.get(link)
    link_content_str = fp.content.decode("utf-8")
    with open(get_html_file_name(link), "w") as s:
        s.write(link_content_str)


def get_episodes(fd, table_index):

    soup = BeautifulSoup(fd, "html.parser")
    doc_content = soup.find("div", {"id": "mw-content-text"})
    #print(doc_content.prettify())
    episode_tables = doc_content.findAll("table")[table_index]
    # for table in  doc_content.findAll("table"):
    #     print(table.prettify())
    links = episode_tables.findAll("a")

    hrefs = []
    for elem in links:
        #print(elem.text)
        if elem.text and "http" not in elem["href"]:
            hrefs.append(elem["href"])
    return hrefs

if not path.isfile("./home.html"):
    fp.save("./home.html")

with open('home.html', 'r') as fd:

    season_links = get_seasons(fd)
    season_table_indexs = [1,1,2,0,0,0,0,0]

    ctr = 0
    ss = 4
    for link, table_index in zip(season_links, season_table_indexs):

        ctr += 1
        if not ctr == ss:
            continue

        # save_season(link)
        print(link)
        with open(get_html_file_name(link), "r") as sf:

            episode_links = get_episodes(sf, table_index)
            print(episode_links)
