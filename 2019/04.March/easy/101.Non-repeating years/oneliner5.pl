my $n;
scalar keys { map { $_ => 1 } split // } < 4 || $n++ for (1980..1987);
say $n;

#bonus
my ($m, $n, $r, $l);
for (1000..2013) {
	$r = scalar keys { map { $_ => 1 } split // } < 4;
	$r == $l && $n++ && next;
	$n > $m->{ $r } && ($m->{ $r } = $n);
	($l, $n) = ($r, 1);
}
