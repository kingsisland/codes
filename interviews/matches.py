
def remoteCast(lowestChannel, highestChannel, blockedChannels, channelsToView):
    # Write your code here
    l=[]
    print(channelsToView)
    for i in range(0,len(channelsToView)):
        for j in range(i+1,len(channelsToView)):
            if(channelsToView[j]>channelsToView[i]):
                p=min(len(str(channelsToView[j])),channelsToView[j]-channelsToView[i])
            else:
                p=min(len(str(channelsToView[j])),channelsToView[i]-channelsToView[j])
            l.append(p)
            break

    return 1+sum(l)