   share[0] = abs(self[topping[0]] - brother[topping[0]]);

    for (int i = 1; i < topping.size(); i++)
    {
        self[topping[i]] += 1;
        if (brother[topping[i]])
            brother[topping[i]] -= 1;
    }