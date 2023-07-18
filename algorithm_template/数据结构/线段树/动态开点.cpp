

// 还未验证
using ll = long long;
struct Node {
    ll v, lz, ls, rs;
    Node(): v(0), lz(0), ls(0), rs(0) {}
};
class SegTree {
    vector<Node> tr;
    ll cnt;
    void push_down(ll p, ll len) {
        if (!tr[p].ls) tr[p].ls = ++cnt, tr.emplace_back(Node{});
        if (!tr[p].rs) tr[p].rs = ++cnt, tr.emplace_back(Node{});
        if (!tr[p].lz) return;
        ll lz = tr[p].lz;
        tr[tr[p].ls].v = lz;
        tr[tr[p].rs].v = lz;
        tr[tr[p].ls].lz = tr[tr[p].rs].lz = lz;
        tr[p].lz = 0;
    }
    void push_up(ll p) {
        tr[p].v = max(tr[tr[p].ls].v , tr[tr[p].rs].v);
    }
public:
    SegTree(): tr(1), cnt(0) {}

    void modify(ll l, ll r, ll L, ll R, ll v, ll p = 0) {
        if (l <= L && r >= R) {
            tr[p].lz = v, tr[p].v = v;
            return;
        }
        ll mid = (L + R - 1) / 2;
        push_down(p, R - L + 1);
        if (mid >= l) modify(l, r, L, mid, v, tr[p].ls);
        if (mid < r) modify(l, r, mid + 1, R, v, tr[p].rs);
        push_up(p);
    }

    ll query(ll l, ll r, ll L, ll R, ll p = 0) {
        if (l <= L && r >= R) return tr[p].v;
        ll mid = (L + R - 1) / 2, ret = 0;
        push_down(p, R - L + 1);
        if (mid >= l) ret = max(ret, query(l, r, L, mid, tr[p].ls));
        if (mid < r) ret = max(ret, query(l, r, mid + 1, R, tr[p].rs));
        return ret;
    }
};