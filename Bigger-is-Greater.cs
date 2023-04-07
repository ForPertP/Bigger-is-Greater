using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Result
{

    /*
     * Complete the 'biggerIsGreater' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts STRING w as parameter.
     */

    public static string biggerIsGreater(string w)
    {
        var charArray = w.ToCharArray();
        if (NextPermutation(charArray))
        {
            return new string(charArray);
        }
        else
        {
            return "no answer";
        }
    }

    public static bool NextPermutation(char[] array)
    {
        int i = array.Length - 2;
        while (i >= 0 && array[i] >= array[i + 1])
        {
            i--;
        }

        if (i < 0)
        {
            return false;
        }

        int j = array.Length - 1;
        while (j > i && array[j] <= array[i])
        {
            j--;
        }

        Swap(array, i, j);

        Array.Reverse(array, i + 1, array.Length - i - 1);

        return true;
    }

    public static void Swap(char[] array, int i, int j)
    {
        char temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

}

class Solution
{
    public static void Main(string[] args)
    {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        int T = Convert.ToInt32(Console.ReadLine().Trim());

        for (int TItr = 0; TItr < T; TItr++)
        {
            string w = Console.ReadLine();

            string result = Result.biggerIsGreater(w);

            textWriter.WriteLine(result);
        }

        textWriter.Flush();
        textWriter.Close();
    }
}
