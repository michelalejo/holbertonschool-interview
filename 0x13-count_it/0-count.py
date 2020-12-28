#!/usr/bin/python3

""" Recursive function that queries the Reddit API"""
import requests


def count_words(subreddit, word_list, after='', lists={}):
    """ Recursive function that queries the Reddit API"""
    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    h = {'User-Agent': 'python3:holberton.task:v1.0'}
    payload = {'limit': '100', 'after': after}
    r = requests.get(url, headers=h, params=payload, allow_redirects=False)
    if not r.status_code == 200:
        return

    data = r.json().get('data')
    after = data.get('after')
    children = data.get('children')
    for child in children:
        title = child.get('data').get('title')
        for word in word_list:
            incident = title.lower().split().count(word.lower())
            if incident > 0:
                if word in lists:
                    lists[word] += incident
                else:
                    lists[word] = incident

    if after is not None:
        return count_words(subreddit, word_list, after, lists)
    else:
        if not len(lists) > 0:
            return

        datas = sorted(lists.items(), key=lambda kv: (-kv[1], kv[0]))
        for key, value in datas:
            print('{}: {}'.format(key.lower(), value))
