(n,m,k),(x,s),a,b,c,d=(list(map(int,input().split()))for _ in" "*6)
a+=[x];b+=[0];c=[0]+c;d=[0]+d
L=sorted(list(zip(a,b)),key=lambda x:-x[1])
o,j=n*x,0
for ai,bi in L:
    while j<=k and d[j]+bi<=s:j+=1
    if j==0:continue
    t=ai*(n-c[j-1])
    o=min(o,t)
print(o)