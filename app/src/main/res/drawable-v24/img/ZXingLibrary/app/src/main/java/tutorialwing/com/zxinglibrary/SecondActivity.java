package tutorialwing.com.zxinglibrary;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

public class SecondActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);

        getFragmentManager()
                .beginTransaction()
                .add(R.id.rootContainer, new QRCodeFragment(), "")
                .commit();
    }
}
