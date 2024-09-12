/**
 * Author: Dario
 * Date: 2024
 * License: CC0
 * Source: me
 * Description: Li-Chao tree.
 * Time: 
 * Usage: 
 * Status: not stress-tested
 */

struct line{
    int a,b;
    line(int aa,int bb){
        a=aa;
        b=bb;
    }

    int eval(int x){
        return a*x+b;
    }
};

double inter(line l1, line l2){
    return ((double) l2.b-l1.b)/(l1.a-l2.a);
}

struct lct{
    vector<line> tree;
    int n;
    vector<vector<pair<int,line>>> history;

    lct(int nn){
        n=nn;
        tree=vector<line>(4*n+8,line(0,0));
    }

    void add(line l, int ac, int acl, int acr){ //ac=1
        if (ac==1) history.pb({});

        if (l.eval(acl)>=tree[ac].eval(acl) && l.eval(acr)>=tree[ac].eval(acr)){
            history.back().pb(pair<int,line>{ac,tree[ac]});
            tree[ac]=l;
        }
        else if (l.eval(acl)<=tree[ac].eval(acl) && l.eval(acr)<=tree[ac].eval(acr)) return;
        else{
            double mid = inter(l,tree[ac]);
            if ((mid<(acr+acl)/2+0.5) && l.eval(acl)>=tree[ac].eval(acl)) add(l,2*ac,acl,(acl+acr)/2);
            if ((mid<(acr+acl)/2+0.5) && l.eval(acl)<=tree[ac].eval(acl)){
                add(tree[ac],2*ac,acl,(acl+acr)/2);
                history.back().pb(pair<int,line>{ac,tree[ac]});
                tree[ac]=l;
            }
            if ((mid>=(acr+acl)/2+0.5) && l.eval(acr)>=tree[ac].eval(acr)) add(l,2*ac+1,(acl+acr)/2+1,acr);
            if ((mid>=(acr+acl)/2+0.5) && l.eval(acr)<=tree[ac].eval(acr)){
                add(tree[ac],2*ac+1,(acl+acr)/2+1,acr);
                history.back().pb(pair<int,line>{ac,tree[ac]});
                tree[ac]=l;
            }
        }
    }

    int getmax(int obj, int ac, int acl, int acr){
        if (acl==acr) return tree[ac].eval(obj);
        if (obj<=(acl+acr)/2) return max(tree[ac].eval(obj),getmax(obj,2*ac,acl,(acl+acr)/2));
        else return max(tree[ac].eval(obj),getmax(obj,2*ac+1,(acl+acr)/2+1,acr));
    }

    void rollback(){
        for (pair<int,line> p:history.back()) tree[p.fi]=p.se;
        history.pop_back();
    }

};