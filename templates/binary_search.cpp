int ans = 0;
for (int k = 1 << 29; k != 0; k /= 2)
  if (is_ok(ans + k))
    ans += k;