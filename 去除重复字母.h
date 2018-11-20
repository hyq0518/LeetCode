/*
贪心算法，逐个字母找出。例如要找出第一个字母，首先找到最右边的一个点，使该点右边能够包含全部的字母，
则第一个字母必在该点左边（包含该点），寻找方法是从该点向左搜寻，搜寻到一个字母表最靠前的、位置最靠左的字母，
则为第一个字母。
*/
public String removeDuplicateLetters(String s) 
{
   if(s==null || s.length()<=0)
	   return "";
   else 
   {
	   int[] count=new int[26];
	   for(int i=0;i<s.length();i++)
		   count[s.charAt(i)-'a']++;
	   int pos=0;
	   for(int i=0;i<s.length();i++)
	   {
		   if(s.charAt(i)<s.charAt(pos))
			   pos=i;
		   count[s.charAt(i)-'a']--;
		   if(count[s.charAt(i)-'a']==0)
			   break;
	   }
	   //System.out.println(s.charAt(pos)+"     "+s.substring(pos+1).replace(""+s.charAt(pos),""));
	   String res = s.charAt(pos)+ removeDuplicateLetters(s.substring(pos+1).replace(""+s.charAt(pos),""));
	   return res;
   }
}