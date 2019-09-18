public interface IDBQuery
{
 String request();
}

 public class DBQuery implements IDBQuery{
 public DBQuery(){
 try{
 Thread.sleep(1000);//假设数据库连接等耗时操作
 }
 catch(InterruptedException ex)
 {
 ex.printStackTrace();
 }
 }
@Override
public String request() {
// TODO Auto-generated method stub
return "request string";
}  
}

public class DBQueryProxy implements IDBQuery{
private DBQuery real = null;
  
@Override
public String request() {
// TODO Auto-generated method stub
//在真正需要的时候才能创建真实对象，创建过程可能很慢
if(real==null){
real = new DBQuery();
}//在多线程环境下，这里返回一个虚假类，类似于 Future 模式

return real.request();
} 
}

 public class Main {
 public static void main(String[] args){
 IDBQuery q = new DBQueryProxy(); //使用代里
 q.request(); //在真正使用时才创建真实对象                 //即就是q.request()调用时才会真正加载，前面只是一个预加载
 }
}
