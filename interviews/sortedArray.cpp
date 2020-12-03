
Written by Anonymous

bool checkRotatedAndSorted(int arr[], int num)
{
    
    int flaga=1,flagb=1;
    
    int maxarr=INT_MIN;
    int maxind=-1;
    
    for(int i=0;i<num;i++)
    {
        if(arr[i]>maxarr)
        {
          maxarr=arr[i];
          maxind=i;
        }  
    }
    
    int minarr=INT_MAX;
    int minind=-1;
    
     for(int i=0;i<num;i++)
     {
        if(arr[i]<minarr)
       { 
           minarr=arr[i];
           minind=i;
       }    
    }

    
         
        if(maxind==minind-1) //increasingly sorted case
        {
            int flag1=1,flag2=1;
            
            for(int i=1;i<minind;i++)            //Check if array is increasing upto Max. Element
            {
                if(arr[i]<arr[i-1])
                {
                    flag1=0;
                    break;
                }    
            }
            for(int i=minind+1;i<num;i++)          //Check if array is increasing again after Min Element
            {
                if(arr[i]<arr[i-1])
               {
                flag2=0;
                break;
               }
            }
            
            if(flag1 && flag2 && (arr[0]>arr[num-1]))         //Check if Last Element is smaller than the first element
            return true;
            else 
            return false;
        }
    
    
    
    
    else if (minind==maxind-1)                //decreasingly sorted case
        {
           int flaga=1,flagb=1;
           
           for(int i=1;i<maxind;i++)           //Check if array is decreasing upto Min. Element
           {
               if(arr[i]>arr[i-1])
               {
               flaga=0;
               break;
               }
           }
           for(int i=maxind+1;i<num;i++)           //Check if array is decreasing again after Max Element
           {
               if(arr[i]>arr[i-1])
               {
               flagb=0;
               break;
               }
           }
          
           if(flaga && flagb && (arr[0]<arr[num-1]))            //Check if Last Element is larger than the first element
           return true;
           else
           return false;
        }
        
    else if(maxind==0 && minind == 1)        //  special case eg  left rotated by 1 =  { 37, 1 , 2 , 3, 4, 5}  other loops fail here
    {   
        int flag=1;
    
        for(int i=2;i<num;i++)
        {
            if(arr[i]<arr[i-1])
            {
                flag=0;
                break;
            }
        }
        if(flag && arr[0]>arr[num-1])
        return true;
    }
    else
    return false;
    
}
