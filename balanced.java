import java.util.Stack;

public class BalancedParentheses {
   public static int longestBalanced(String str) {
     int maxans = 0;
     Stack<Integer> stack = new Stack<>();
     stack.push(-1);
     for (int i = 0; i < str.length(); i++) {
       if (str.charAt(i) == '(') {
         stack.push(i);
       } else {
         stack.pop();
         if (stack.empty()) {
           stack.push(i);
         } else {
           maxans = Math.max(maxans, i - stack.peek());
         }
       }
     }
       return maxans;
   }
}