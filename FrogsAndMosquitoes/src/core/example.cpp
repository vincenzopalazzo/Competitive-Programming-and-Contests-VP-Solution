#include<cstdio>
#include<algorithm>
#include<set>
#define pr pair<long,long>
using namespace std;
typedef long long ll;

const int maxn=2e5+5;

struct node
{
    ll pos,len;
    int id;
    bool operator <(const node &a)const
    {
        return pos<a.pos;
    }
}a[maxn];

struct T
{
    int l, r;
    ll MAX;
}tree[maxn<<2];

pr mos[maxn];//记录蚊子的坐标和size
int ans[maxn];//记录青蛙吃到的蚊子数量
ll len[maxn];//记录青蛙的舌头长度
ll x[maxn];//记录青蛙的坐标
int n,m;

void build(int i,int l,int r)
{
    tree[i].l=l,tree[i].r=r;
    if(l==r)
    {
        tree[i].MAX=a[l].pos+a[l].len;
        return ;
    }
    int mid=(l+r)>>1;
    build(i<<1,l,mid);
    build(i<<1|1,mid+1,r);
    tree[i].MAX=max(tree[i<<1].MAX,tree[i<<1|1].MAX);
}

ll query(int i,int l,int r)
{
    if(tree[i].l==l&&tree[i].r==r)
        return tree[i].MAX;
    int mid=(tree[i].l+tree[i].r)>>1;
    if(r<=mid)
        return query(i<<1,l,r);
    else if(l>mid)
        return query(i<<1|1,l,r);
    else
        return max(query(i<<1,l,mid),query(i<<1|1,mid+1,r));
}

void update(int i,int pos,ll v)
{
    if(tree[i].l==tree[i].r)
    {
        tree[i].MAX+=v;
        return ;
    }
    int mid=(tree[i].l+tree[i].r)>>1;
    if(pos<=mid)
        update(i<<1,pos,v);
    else
        update(i<<1|1,pos,v);
    tree[i].MAX=max(tree[i<<1].MAX,tree[i<<1|1].MAX);
}

int solve(ll pos)//找能吃到pos这个位置的蚊子的最左侧的青蛙
{
    int l=1,r=upper_bound(x+1,x+1+n,pos)-x-1;
    if(r==0||query(1,1,r)<pos)//吃不到
        return -1;
    int mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(query(1,1,mid)<pos)
            l=mid+1;
        else
            r=mid-1;
    }
    return l;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&a[i].pos,&a[i].len),a[i].id=i;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        x[i]=a[i].pos;
    for(int i=1;i<=m;i++)
        scanf("%lld%lld",&mos[i].first,&mos[i].second);
    build(1,1,n);
    multiset<pr> s;
    for(int i=1;i<=m;i++)
    {
        int pos=solve(mos[i].first);
        if(pos==-1)//暂时没有青蛙能吃到这只蚊子
            s.insert(mos[i]); //插入到set集合中
        else//有青蛙能吃到这只蚊子
        {
            ans[a[pos].id]++;//记录这只青蛙吃到的蚊子数量
            a[pos].len+=mos[i].second;//青蛙的舌头长度增加
            update(1,pos,mos[i].second);
            ll tmp=a[pos].pos+a[pos].len;//这只青蛙能吃到的最靠右侧的蚊子
            while(!s.empty())//看这只青蛙是不是能吃到以前不能吃到的蚊子
            {
                multiset<pr>:: iterator it=s.lower_bound(pr(a[pos].pos,0));//找到在这只青蛙右侧的第一只蚊子
                if(it==s.end()||it->first>tmp)//没有找到或者这只蚊子太远了 还是吃不到
                    break;
                tmp+=it->second;//该青蛙现在能吃到这只蚊子了
                ans[a[pos].id]++;//更新数量
                a[pos].len+=it->second;//更新长度
                update(1,pos,it->second);
                s.erase(it);//从set中删去这只蚊子
            }
        }
    }
    for(int i=1;i<=n;i++)
        len[a[i].id]=a[i].len;
    for(int i=1;i<=n;i++)
        printf("%d %lld\n",ans[i],len[i]);
    return 0;
}