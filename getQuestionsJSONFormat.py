import requests
url = "https://opentdb.com/api.php?amount=10&type=multiple"
with open("questions.txt","w") as file:
    file.write(requests.get(url).text)