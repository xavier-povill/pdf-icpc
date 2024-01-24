/**
 * Author: 
 * Date: 
 * License: 
 * Source: 
 * Description: 
 * Time: 
 * Usage: 
 * Status: 
 */
#define vi vector<int>
struct LazySegmentTree{
    //MODIFY INF IF USING LONG LONG
    const int INF=2e9;
    int n;
    vi tree;
    vi lazy;

    LazySegmentTree(int x) : n{x} {
        tree=vi(4*n+5,0);
        lazy=vi(4*n+5,0);
    }

    void push(int id, int l, int r){
        if (l==r){
            tree[id]+=lazy[id];
            lazy[id]=0;
        }
        else{
            lazy[2*id]+=lazy[id];
            lazy[2*id+1]+=lazy[id];
            tree[id]=min(tree[2*id]+lazy[2*id],tree[2*id+1]+lazy[2*id+1]);
            lazy[id]=0;
        }
    }

    void upd(int l, int r, int x, int acl, int acr, int id=1){
        if (acl>r || acr<l) return;
        if (acl>=l && acr<=r){
            lazy[id]+=x;
            //push(id,acl,acr); //?
        }
        else{
            push(id,acl,acr);
            upd(l,r,x,acl,(acl+acr)/2,2*id);
            upd(l,r,x,(acl+acr)/2+1,acr,2*id+1);
            tree[id]=min(tree[2*id]+lazy[2*id],tree[2*id+1]+lazy[2*id+1]);
        }
    }

    int getmin(int l, int r, int acl, int acr, int id=1){
        if (acl>r || acr<l) return INF;
        if (acl>=l && acr<=r) return tree[id]+lazy[id];
        else{
            push(id,acl,acr);
            return min(getmin(l,r,acl,(acl+acr)/2,2*id),getmin(l,r,(acl+acr)/2+1,acr,2*id+1));
        }
    }
};
