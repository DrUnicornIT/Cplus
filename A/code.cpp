pushDown(id, l, r) {
    val[id] += lz[id] * (r - l + 1); ///
    if (l != r) {
        lz[id * 2] += lz[id];
        lz[id * 2 + 1] += lz[id];
    }
    lz[id] = 0;
}       

Update(id, l, r, u, v , val) {
    pushDown(id, l, r); -> val[id] Đúng 
    ìf() return

    if(l >= u && r <= v) {
        lz[id] += val;
        pushDown(id, l, r);
        return;
    }

    int mid = (l + r) / 2;
    Update(id * 2, l, mid, u, v, val), Update(id * 2 + 1, mid + 1, r, u, v, val);
    val[id] = val[id * 2] + val[id * 2 + 1];
    
}

Get() {
    pushDown(id) -> val[id] đúng  
    return val[id
}
