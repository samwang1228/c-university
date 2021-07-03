    for (int i = 0; i < x;i++) // release memory of malloc
        free(p[i]);
    free(p);
