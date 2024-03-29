//{ Driver Code Starts
import java.util.*;

class Merge_Sort
{
    //method to print the elements of the array
	static void printArray(int arr[])
    {
        StringBuffer sb=new StringBuffer("");
        int n = arr.length;
        for (int i=0; i<n; ++i)
            sb.append(arr[i]+" ");
        System.out.println(sb.toString());
    }

    

	public static void main(String args[])
	{
	    //taking input using Scanner class
		Scanner sc = new Scanner(System.in);
		
		//taking testcases
		int T = sc.nextInt();
		while(T>0)
		{
		    //taking elements count
			int n = sc.nextInt();
			
			//creating an object of class Merge_Sort
			Merge_Sort ms = new Merge_Sort();
			
			//creating an array of size n
			int arr[] = new int[n];
			
			//adding elements to the array
			for(int i=0;i<n;i++)
				arr[i] = sc.nextInt();

            
			Solution g = new Solution();
			
			//calling the method mergeSort
			g.mergeSort(arr,0,arr.length-1);

            //calling the method printArray
			ms.printArray(arr);
		T--;
		}
	}
}



// } Driver Code Ends

class Solution
{
    void merge(int arr[], int l, int mid, int r)
    {
        int ans[]=new int[r-l+1];
        
        int i=l,k=0,j=mid+1;
        while(i<=mid&&j<=r)
        {
            if(arr[i]<arr[j]){
                ans[k++]=arr[i++];
            }else{
                ans[k++]=arr[j++];
            }
        }
        while(i<=mid){
            ans[k++]=arr[i++];
        }
        while(j<=r){
            ans[k++]=arr[j++];
        }
        for(i=0;i<ans.length;i++){
            arr[i+l]=ans[i];
        }
        return;
    }
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        int mid;
        if(l<r)
        {
            mid=l+(r-l)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            merge(arr,l,mid,r);
        }
        return;
    }
}
