void main()
{
    int a;
    int b;
    {
	    {a = 0;}
        b = 0;
	}
    if (a != 5)
    if (a == 1) 
    	a = 3;
    else
    	a = 10;
    do {
    	a = 0;
    } while (!(1 == 1));
    while(1 != 1)
    	a = 1;
    b = (a > 10 ? 5 : b > 10 ? 6 : 7) == 7 ? 15 : 16;
    b = a > 10 ? 5 : 7 == 7 ? 15 : 16;
    
    b = (a == 0 && b >= 0 || a < 0) ? 5 : 6;
}
