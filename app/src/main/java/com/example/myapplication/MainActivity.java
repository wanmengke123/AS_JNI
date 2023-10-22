package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.example.myapplication.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'myapplication' library on application startup.
//    static {
//        System.loadLibrary("myapplication");
//    }
//    Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }
    private String name="Derry";// 等下 用 C++代码，修改为Beyond
    public static int age = 28;
    private ActivityMainBinding binding;
    public native void  changeName();
    public static native void  changeAge();
    public native void  callMethod();
    // (I)V
    public int add(int number1, int num2){
        return number1+num2;
    }
// 被C调用的方法 (Ljava/ ang/string;I)Ljava/ ang/string;
public String showString(String str,int value) {
        System.out.println("C居然调用了我 showString str:" + str + " value:" + value);
        return "[" + str + "]";
    }
    /**
     * A native method that is implemented by the 'myapplication' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        TextView tv = binding.sampleText;
        tv.setText(stringFromJNI());

        Log.d("cyh", "name修改前是:" + name);
        changeName();
//        System.out.println("name修改后是:" + name);
        Log.d("cyh", "name修改后是:" + name);
        Log.d("cyh", "age修改前是:" + age);

        changeAge();
        Log.d("cyh", "age修改后是:" + age);


    }


}