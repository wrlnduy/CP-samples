    const int N = 1e5;

    int inp[N];

    struct node{
        node *l = nullptr, *r = nullptr;
        int sum = 0;
        node(int sum = 0) : sum(sum){}
        node(node *l, node *r) : l(l), r(r){
            sum = l->sum + r->sum;
        }
    };

    node *build(int tl, int tr){
        if(tl == tr) return new node();
        int tm = (tl + tr)/2;
        return new node(build(tl, tm), build(tm+1, tr));
    }

    //Update one element by adding LogN nodes
    //Given an array
    //1 0 5 ...
    //update(roots[0], 1, n, 1)
    //update(roots[1], 1, n, 0)
    //update(roots[2], 1, n, 5)...

    node *update(node *v, int tl, int tr, int pos){
        if(pos < tl || pos > tr) return v;
        if(tl == tr) return new node(inp[pos]);
        int tm = (tl + tr)/2;
        return new node(update(v->l, tl, tm, pos), update(v->r, tm+1, tr, pos));
    }

    //Find K-th element on segment [l, r];
    //int l, r, k;
    //get(roots[r], roots[l-1], 1, n, k)

    int get(node *vr, node *vl, int tl, int tr, int k){
        if(tl == tr) return tl;
        int tm = (tl + tr)/2;
        int amount_left = vr->l->sum - vl->l->sum;
        if(amount_left >= k) return get(vr->l, vl->l, tl, tm, k);
        return get(vr->r, vl->l, tm+1, tr, k-amount_left)
    }

