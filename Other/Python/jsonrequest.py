# Code used in JSON Request challenge.

import requests
from requests.structures import CaseInsensitiveDict

# Edit these.
# url = Challenge site URL. (Remember "/" at the end.)
# name = JSON Name.
url = "www.github.com/silsanteri/"
name = "next"

end = ""
headers = CaseInsensitiveDict()
headers["Accept"] = "application/json"

while(1):
    url2 = url + end
    resp = requests.get(url2, headers=headers)
    end = resp.json()[name]

    print(resp.json())
