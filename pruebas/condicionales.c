int suich(int a,int b,int c)
{
	float x=12.5, y=10.0, z;
	int p1 = 0, p2 = 1;

	z = x + y

	if (p1 == p2)
	{
		x++;
	}
	else
	{
		if (p1 > p2)
		{
			y++;
		}
		else
		{
			z++;
		}
	}

	switch(c)
	{
		case 1:
			return a+1;
			break;
		case 2: 
			return b+1;
			break;
		default:
			return 1;
			break;
	}

}

int main(){
	return suich(1, 3, 5);
}
