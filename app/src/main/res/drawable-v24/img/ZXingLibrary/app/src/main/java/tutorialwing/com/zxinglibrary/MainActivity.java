package tutorialwing.com.zxinglibrary;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import com.google.zxing.integration.android.IntentIntegrator;
import com.google.zxing.integration.android.IntentResult;

import org.json.JSONException;
import org.json.JSONObject;

public class MainActivity extends AppCompatActivity {

    TextView txtName;

    TextView txtSiteName;

    Button btnScan;

    IntentIntegrator qrScanIntegrator;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        txtName = findViewById(R.id.name);
        txtSiteName = findViewById(R.id.site_name);

        btnScan = findViewById(R.id.btnScan);
        if (btnScan != null) {
            btnScan.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    performAction();
                }
            });
        }

        qrScanIntegrator = new IntentIntegrator(this);
        qrScanIntegrator.setOrientationLocked(false);

        // Different Customization option...
        qrScanIntegrator.setPrompt(getString(R.string.scan_a_code));
        qrScanIntegrator.setCameraId(0);  // Use a specific camera of the device
        qrScanIntegrator.setBeepEnabled(false);
        qrScanIntegrator.setBarcodeImageEnabled(true);

        Button button = findViewById(R.id.showQRScanner);
        if (button != null) {
            button.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    startActivity(new Intent(MainActivity.this, SecondActivity.class));
                }
            });
        }
    }

    private void performAction() {
        qrScanIntegrator.initiateScan();
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        IntentResult result = IntentIntegrator.parseActivityResult(requestCode, resultCode, data);
        if (result != null) {
            // If QRCode has no data.
            if (result.getContents() == null) {
                Toast.makeText(this, getString(R.string.result_not_found), Toast.LENGTH_LONG).show();
            } else {
                // If QRCode contains data.
                try {
                    // Converting the data to json format
                    JSONObject obj = new JSONObject(result.getContents());

                    // Show values in UI.
                    txtName.setText(obj.getString("name"));
                    txtSiteName.setText(obj.getString("site_name"));

                } catch (JSONException e) {
                    e.printStackTrace();

                    // Data not in the expected format. So, whole object as toast message.
                    Toast.makeText(this, result.getContents(), Toast.LENGTH_LONG).show();
                }
            }
        } else {
            super.onActivityResult(requestCode, resultCode, data);
        }
    }
}
