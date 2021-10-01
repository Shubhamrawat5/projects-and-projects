# IBM Data Science Professional Certificate | Applied Data Science Capstone

Coursera Course Link: https://www.coursera.org/professional-certificates/ibm-data-science 

## Introduction:
The purpose of this project is to help people in exploring better facilities around their neighborhood. It will help people making smart and efficient decisions on selecting a great neighborhood out of a number of other neighborhoods in Scarborough, Toronto.

A lot of people migrate to various states of Canada, and they do a lot of research for good housing prices and reputed schools for their children. This project is for those people who are looking for better neighborhoods, which have easy access to various cafes, schools, super-markets, medical shops, grocery shops, malls, theatres, hospitals, etc.

This Project aims to create an analysis of features for people migrating to Scarborough in search of the best neighborhood as a comparative analysis between neighborhoods.

## Data Selection
Data Link: https://en.wikipedia.org/wiki/List_of_postal_codes_of_Canada:_M

I have used data scraped from the "List of Postal Codes of Canada" Wiki page.

### Foursquare API Data:
I needed data about different venues in different neighborhoods of that specific borough. In order to gain that information I used "Foursquare" locational information. Foursquare is a location data provider with information about all manner of venues and events within an area of interest. Such information includes venue names, locations, menus and even photos. As such, the foursquare location platform was used as the sole data source since all the stated required information was obtained through the API.

After finding the list of neighborhoods, I then connected to the Foursquare API to gather information about venues inside each and every neighborhood. For each neighborhood, I chose the radius to be 100 meters.

The data retrieved from Foursquare contained information of venues within a specified distance of the longitude and latitude of the postcodes. The information obtained per venue as follows:
*  Neighborhood
*  Neighborhood Latitude
*  Neighborhood Longitude
*  Venue
*  Name of the venue e.g. the name of a store or restaurant
*  Venue Latitude
*  Venue Longitude
*  Venue Category

## Methodology

### Clustering Approach:
To compare the similarities of two cities, I decided to explore neighborhoods, segment them, and group them into clusters to find similar neighborhoods in a big city like New York and Toronto. To be able to do that, I needed to cluster data which was a form of unsupervised machine learning: K-means Clustering algorithm.

### Work Flow:
Using credentials of the Foursquare API, features of near-by places of the neighborhoods were mined. Due to http request limitations the number of places per neighborhood parameter was reasonably be set to 100 and the radius parameter was set to 500.

## Results

### The Location:
Scarborough is a popular destination for new immigrants in Canada to reside. As a result, it is one of the most diverse and multicultural areas in the Greater Toronto Area, being home to various religious groups and places of worship. Although immigration has become a hot topic over the past few years with more governments seeking more restrictions on immigrants and refugees, the general trend of immigration into Canada has been one of on the rise.

### Foursquare API:
This project has used the Four-square API as its prime data gathering source as it has a database of millions of places, especially their places API which provides the ability to perform location search, location sharing and details about a business.

## Discussion

### Problem Which I Tried to Solve:
The major purpose of this project, is to suggest a better neighborhood in a new city for the person who are shiffting there. Social presence in society in terms of like minded people. Connectivity to the airport, bus stand, city center, markets and other daily needs things nearby.
* Sorted list of house in terms of housing prices in a ascending or descending order

## Conclusion
In this project, using the K-means Clustering algorithm, I separated the neighborhood into 10 different clusters for 103 different latitude and longitude points from the dataset, which have similar neighborhoods around them. Using the chart generated, results of a particular neighborhood based on average house prices are presented.

I feel rewarded with the efforts and believe this course with all the topics covered is well worthy of appreciation. This project has shown me a practical application to resolve a real situation that has impacting personal and financial impact using Data Science tools. The mapping with Folium is a very powerful technique to consolidate information and make the analysis and decision better with confidence.

### Future Works
This project can be continued for making it more precise in terms to find best house in Scarborough. Best means on the basis of all required things(daily needs or things we need to live a better life) around and also in terms of cost effective.

### Libraries used to develop the project:
* Pandas: For creating and manipulating dataframes.
* Folium: Python visualization library would be used to visualize the neighborhoods cluster distribution of using interactive leaflet map.
* Scikit Learn: For importing k-means clustering.
* JSON: Library to handle JSON files.
* XML: To separate data from presentation and XML stores data in plain text format.
* Geocoder: To retrieve Location Data.
* Beautiful Soup and Requests: To scrap and library to handle http requests.
* Matplotlib: Python Plotting Module.
