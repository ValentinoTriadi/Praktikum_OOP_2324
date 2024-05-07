public class Palindrome<T> {
    //Method untuk mengecek apakah Deque dq merupakan palindrome
    //Deque dq merupakan palindrome jika elemen-elemen pada Deque dq dapat dibaca sama dari depan dan belakang
    public boolean isPalindrome(Deque<T> dq){
        Deque<T> dq2 = new Deque<T>(dq);
        while(!dq.isEmpty()){
            try{
                T t1 = dq.popFront();
                T t2 = dq2.popBack();
                if(!t1.equals(t2)){
                    return false;
                }
            }catch(Exception e){
                e.printStackTrace();
            }
        }
        return true;
    }
}