#!/usr/bin/python3
"""
    A recursive function "count_words" that queries the Reddit API to retrieve
    all "hot" articles from a given subreddit, counts the occurrences of
    specified keywords in the article titles, and prints the results sorted by
    count (descending order) and alphabetically (ascending, from a to z).
"""
import re
import requests


def count_words(subreddit, word_list, counts=None, after=None):
    """
        Queries the Reddit API, parses the title of all hot articles,
        and prints a sorted count of given keywords.

        Args:
            subreddit (str): the name of the subreddit to query.
            word_list (list of str): a list of keywords to count in article
                titles.
            counts (dict, optional): used internally to track counts across
                recursive calls. Default is None.
            after (str, optional): the parameter for Reddit pagination.
                Default is None.
    """
    if counts is None:
        counts = {}
        normalized = [keyword.lower() for keyword in word_list]
        for keyword in normalized:
            counts[keyword] = counts.get(keyword, 0)
        word_list = normalized

    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    headers = {"User-Agent": "python:countwords:v1.0 (by /u/holberton)"}
    params = {"limit": 100}
    if after:
        params["after"] = after

    try:
        response = requests.get(url, headers=headers, params=params,
                                allow_redirects=False)
        if response.status_code != 200:
            return
    except requests.RequestException:
        return

    data = response.json().get("data", {})
    posts = data.get("children", [])

    for post in posts:
        title = post.get("data", {}).get("title", "").lower()
        for word in counts.keys():
            matches = re.findall(rf"\b{re.escape(word)}\b", title)
            counts[word] += len(matches)

    next_after = data.get("after")
    if next_after:
        return count_words(subreddit, word_list, counts, next_after)

    sorted_counts = sorted(
        [(word, count) for word, count in counts.items() if count > 0],
        key=lambda x: (-x[1], x[0])
    )
    for word, count in sorted_counts:
        print(f"{word}: {count}")
