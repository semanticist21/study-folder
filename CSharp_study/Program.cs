using System;

public class Solution
{
    // public int[][] func_a(int[][] arr)
    // {
    //     int[][] ret = new int[arr.Length][];
    //     for (int i = 0; i < arr.Length; i++)
    //     {
    //         ret[i] = new int[[[quiz]]];
    //         Array.Sort(arr[i]);
    //         for (int j = 1; j < [[quiz]]; j++)
    //             [[quiz]];
    //     }
    //     return ret;
    // }

    // public int func_b(int[][] arr)
    // {
    //     int[] ret = new int[arr.Length];
    //     for (int i = 0; i < arr.Length; i++)
    //     {
    //         for (int j = 0; j < arr[i].Length; j++)
    //             [[quiz]];
    //         ret[i] = ret[i] / arr[i].Length;
    //     }
    //     Array.Sort(ret);
    //     return ret[[[quiz]]];
    // }

    public int[][] convertJaggedArray(int[,] arr)
    {
        int[][] jaggedArray = new int[arr.GetLength(0)][];
        for (int i = 0; i < arr.GetLength(0); i++)
        {
            jaggedArray[i] = new int[arr.GetLength(1)];
            for (int j = 0; j < arr.GetLength(1); j++)
                jaggedArray[i][j] = arr[i, j];
        }
        return jaggedArray;
    }

    public int solution(int[,] scores)
    {
        int[][] scoreArray = convertJaggedArray(scores);
        // int[][] arr2 = func_a(scoreArray);
        // int answer = func_b(arr2);
        // return answer;

        return 0;
    }

    // 아래는 테스트케이스 출력을 해보기 위한 main 메소드입니다.
    public static void Main(string[] args)
    {
        Solution sol = new Solution();
        int[,] scores = new int[,] { { 85, 92, 95, 90 }, { 91, 76, 85, 50 } };

        int b = scores[0,1];
        int ret = sol.solution(scores);

        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        Console.WriteLine("solution 메소드의 반환 값은 " + ret + " 입니다.");
    }
}