import java.util.*;
public class FindMaxRectangle {
   private int histogram[];
     private int histogramLen;
     private Stack<Integer> stack;
     int max_area = 0;
     int left_index = 0;
     int right_index = 0;
     
    FindMaxRectangle(int histogram[]) {
    this.histogram = histogram; 
    this.histogramLen = histogram.length;
    this.stack = new Stack<>();
   }
   
   private void calculateArea(int top, int position){
     int right_position = position - 1;
     int left_position = stack.empty() ? 0 : stack.peek() +1;
     int rect_width = right_position - left_position +1;
     int rect_height = histogram[top];
     int area = rect_height*rect_width;
     if (area > max_area){
       max_area = area;
       right_index = right_position;
       left_index = left_position;
     }
   }
     public int[] findMaxRectangle() {
     int top;
     for (int position = 0; position < histogramLen; position++){
       while(!stack.empty() && this.histogram[this.stack.peek()] >= this.histogram[position]){
            top = this.stack.peek();
            this.stack.pop();
            calculateArea(top, position);
       }
       this.stack.push(position);
     }
     while(!this.stack.empty()){
          top = this.stack.peek();
          this.stack.pop();
          calculateArea(top, histogramLen);
     }
      int[] x = new int[2]; 
      x[0] = left_index;
      x[1] = right_index;
     return x;
   }
   public static void main(String[] args){
     int hist1[] = {2,4,2,1};
     FindMaxRectangle finder1 = new FindMaxRectangle(hist1);
     finder1.findMaxRectangle();
     System.out.println("area:" + finder1.max_area+ "left index" + finder1.left_index + "right index" + finder1.right_index);
     
     int hist2[] = {2,4,2,1,10,6,10};
     FindMaxRectangle finder2 = new FindMaxRectangle(hist2);
     finder2.findMaxRectangle();
     System.out.println("area:" + finder2.max_area+ "left index" + finder2.left_index + "right index" + finder2.right_index);
   }
}
