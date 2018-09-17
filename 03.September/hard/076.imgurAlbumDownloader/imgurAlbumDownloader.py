#!/usr/bin/python2

# This code is not mine but works fine, i should study this more
import sys, urllib, urllib2, re, os

album = sys.argv[1]
path = sys.argv[2]

print "Contacting imgur.com ..."
try:
    webPage = urllib2.urlopen("http://api.imgur.com/2/album/" +album + ".json")
    source = webPage.read()
    webPage.close()
except urllib2.HTTPError, e:
    print "Error", e.code, "occured"
    sys.exit()
except urllib2.URLError, e:
    print "Error", e.reason
    sys.exit()

numberOfImages = source.count("original")
print "Found", numberOfImages, "images"
urls = re.findall(r'original":".*?","imgur_page', source)

if(not os.path.exists(path)): os.makedirs(path)

for i in range(numberOfImages):
    print "Downloading image", i + 1, "of", numberOfImages, "..."
    urls[i] = urls[i].replace('original":"', '').replace('","imgur_page', '').replace(chr(92), '')
    filename = path + os.sep + album + '-' + str(i + 1) + '.' +  urls[i].split('.')[len(urls[i].split('.')) - 1]
    try:
        urllib.urlretrieve(urls[i], filename)
    except urllib2.HTTPError, e:
        print "Error", e.code, "occured"
        sys.exit()
    except urllib2.URLError, e:
        print "Error", e.reason
        sys.exit()
print "All images downloaded!"
