    for (int i = 0; i < str2.size(); i += 2)
    {
        if (i >= str2.size() - 1)
            break;

        if (isalpha(str2[i]) && isalpha(str2[i + 1]))
        {
            string s;
            s += str2[i];
            s += str2[i + 1];
            str2_elements[s] += 1;
        }
    }