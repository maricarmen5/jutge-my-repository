#include "llista_compra_articles.hpp"

int compra_articles_aux(list<int>& li, int x)
{
    int ans = 0;

    if (0 < x and (not li.empty())) {
        if (-1 < x - li.front()) {
            ans = 1;
            x -= li.front();
        }

        li.pop_front();

        ans += compra_articles_aux(li, x);
    }

    return ans;
}

int compra_articles(const list<int> &l, int x)
{
    list<int> li = l;
    int ans = compra_articles_aux(li, x);
    return ans;
}
