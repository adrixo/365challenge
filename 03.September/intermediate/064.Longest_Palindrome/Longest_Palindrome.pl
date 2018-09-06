#!/usr/bin/perl

sub lc_substr {
  my ($str1, $str2) = @_;
  my $l_length = 0;
  my $len1 = length $str1;
  my $len2 = length $str2;
  my @char1 = (undef, split(//, $str1));
  my @char2 = (undef, split(//, $str2));
  my @lc_suffix;
  my @substrings;

  for my $n1 ( 1 .. $len1 ) {
    for my $n2 ( 1 .. $len2 ) {
      if ($char1[$n1] eq $char2[$n2]) {
        $lc_suffix[$n1-1][$n2-1] ||= 0;
        $lc_suffix[$n1][$n2] = $lc_suffix[$n1-1][$n2-1] + 1;
        if ($lc_suffix[$n1][$n2] > $l_length) {
          $l_length = $lc_suffix[$n1][$n2];
          @substrings = ();
        }
        if ($lc_suffix[$n1][$n2] == $l_length) {
          push @substrings, substr($str1, ($n1-$l_length), $l_length);
        }
      }
    }
  }

  return @substrings;
}

  # Args: string
  # Return: longest palindrome on it
sub longest_Palindrome {
  my $l_length = 0;

  my @longestcommon_suffix;

  # first we need the reversed string
  my $reversed = reverse $_[0];
  my $len = length $reversed;


   # Now the longest substring
   my @substrings = lc_substr($reversed, $_[0]);
   print "@substrings\n";
   return @substrings;
}

my $string = "FourscoreandsevenyearsagoourfaathersbroughtforthonthiscontainentanewnationconceivedinzLibertyanddedicatedtothepropositionthatallmenarecreatedequalNowweareengagedinagreahtcivilwartestingwhetherthatnareavtptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";

longest_Palindrome($string);



#foreach my $i (1..$len){
#  foreach my $j (1..$len){
#    if( substr($reversed, $i,$i+1) eq substr($_[0], $j,$j+1) ) {
#      $longestcommon_suffix[$i-1][$j-1] ||= 0;
#      $longestcommon_suffix[$i][$j] = $longestcommon_suffix[$i-1][$j-1] + 1;
#
#      if ($longestcommon_suffix[$i][$j] > $l_length) {
#        $l_length = $longestcommon_suffix[$i][$j];
#        @substrings = ();
#      }
#      if ($lc_suffix[$i][$j] == $l_length) {
#        push @substrings, substr($_[0], ($i-$l_length), $l_length);
#      }
#    }
#  }
#}
