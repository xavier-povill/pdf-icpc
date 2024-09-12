/**
 * Author: Pablo
 * Date: 2024-09-12
 * License: CC0
 * Source: me
 * Description: ???
 * Time: 
 * Usage: 
 * Status: proof by AC
 */
const int B = ...;
int xb[B];
void add(int xx) {
    for (int b = B-1; b >= 0; --b) if (xx&(1 << b)) {
        if (xb[b]) xx ^= xb[b];
        else {
            xb[b] = xx;
            break;
        }
    }
}