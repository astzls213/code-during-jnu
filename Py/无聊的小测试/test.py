a=['sdasd', 'aAAsD', 18, None, 'NMSL']

#[for x in a if isinstance(x,str)]
b=[x.lower() for x in a if isinstance(x, str)]
print(b)
