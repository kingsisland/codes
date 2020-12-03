from collections import defaultdict
def distance(x1,y1,x2,y2):
    return abs(x1-x2)+abs(y1-y2)
def nearestCity(numCities,cities,xCordinate,yCordinate,numOfQueries,queries):
    if numCities==0:
        return [0]
    di=defaultdict(list)
    for i in range(numCities):
        di[cities[i]].append(xCordinate[i])
        di[cities[i]].append(yCordinate[i])
    print(di)
    distanceDict=defaultdict(list)
    for i in range(numOfQueries-1):
        q=queries[i]
        for j in range(i+1,numOfQueries):
            x=((distance(di[q][0],di[q][1],di[queries[j]][0],di[queries[j]][1]),queries[j]))
            distanceDict[q].append(x)
            x=((distance(di[q][0],di[q][1],di[queries[j]][0],di[queries[j]][1]),q))
            distanceDict[queries[j]].append(x)
    ans=[]
    for i in range(numOfQueries):
        q=queries[i]
        for (dist,city) in distanceDict[q]:
            
            x1,y1=di[q]
            x2,y2=di[city]
            if x1==x2 or y1==y2:
                ans.append(city)
                break
        else:
            ans.append("None")
    print(ans)

numCities = 3
cities = ["c1", "c2", "c3"]
xCordinate = [3,2,1]
yCordinate = [3,2,3]
numOfQueries = 3
queries = ["c1", "c2", "c3"]
nearestCity(numCities,cities,xCordinate,yCordinate,numOfQueries,queries)