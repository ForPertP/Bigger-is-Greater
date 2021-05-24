string biggerIsGreater(string w)
{
    string result{};
    size_t n = w.length();

    for (int i = n-2; i >= 0; --i)
    {
        for (int j = n-1; j > i; --j)
        {
            if (w[i] < w[j])
            {
                std::swap(w[i], w[j]);
                std::sort(w.begin()+i+1, w.end());
                return w;
            }
        }
    }

    return "no answer";
}


string biggerIsGreater1(string w)
{
    if (next_permutation(w.begin(), w.end()))
    {
        return w;
    }
    else
    {
        return "no answer"; 
    }
} 
