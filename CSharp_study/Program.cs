using System;

namespace CSharp_study
{
    class Program
    {
        static void Main(string[] args)
        {
            // int[][] arr = new int[3][];
            // arr[0] = new int[5] {1,2,3,4,5};
            
            // int[][] arr2 = new int[2][];
            // arr2[0] = new int[6]{ 11,122,222,3333,44444,5454};
            // arr2[1] = new int[3]{ 11,122,33};
            // arr2[2] = new int[2]{ 11,122};

            string[][] arr = new string[2][] {
                new string[] {"a","b"},
                new string[] {"a","c","d","e"}
            };
            foreach(string[] strArr in arr)
                {
                    Console.Write("배열의 크기(길이) : {0}, ",strArr.Length);
                    foreach(string str in strArr)
                    {
                        Console.Write("{0}", str);    
                    }
                    Console.Write("\n");
                }                    

        }
    }
}
