#!/usr/bin/python3
"""
count_words
"""
import requests


def count_words(subreddit, word_list, after=None, word_count={}):
    headers = {'User-Agent': 'Reddit API script'}

    # Fetch data from Reddit API
    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    params = {'limit': 100, 'after': after}  # Pagination using 'after'
    response = requests.get(
        url, headers=headers, params=params, allow_redirects=False
        )

    if response.status_code != 200:
        return

    data = response.json()
    # Extract titles from the response
    titles = [post['data']['title'] for post in data['data']['children']]

    # Normalize the word_list (case insensitive) and prepare for counting
    word_list = [word.lower() for word in word_list]

    # Count occurrences of words in titles
    for title in titles:
        words = title.lower().split()
        for word in word_list:
            word_count[word] = word_count.get(word, 0) + words.count(word)

    after = data['data']['after']
    if after:
        count_words(subreddit, word_list, after, word_count)

    # If we're at the last page, sort and print the results
    if after is None:
        # Filter out words with 0 occurrences
        filtered_word_count = {
            word: count for word, count in word_count.items() if count > 0
            }

        # Sort by count (descending), then by word (alphabetically)
        sorted_word_count = sorted(
            filtered_word_count.items(), key=lambda item: (-item[1], item[0])
            )

        # Print results
        for word, count in sorted_word_count:
            print(f"{word}: {count}")
