package tutorialwing.com.zxinglibrary;

import android.app.Fragment;
import android.content.Intent;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import com.google.zxing.integration.android.IntentIntegrator;
import com.google.zxing.integration.android.IntentResult;

import org.json.JSONException;
import org.json.JSONObject;

public class QRCodeFragment extends Fragment {

    TextView txtName;

    TextView txtSiteName;

    Button btnScan;

    IntentIntegrator qrScanIntegrator;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        return inflater.inflate(R.layout.fragment_qrcode, container, false);
    }

    @Override
    public void onViewCreated(View view, @Nullable Bundle savedInstanceState) {

        txtName = view.findViewById(R.id.name);
        txtSiteName = view.findViewById(R.id.site_name);

        btnScan = view.findViewById(R.id.btnScan);
        if (btnScan != null) {
            btnScan.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    performAction();
                }
            });
        }

        qrScanIntegrator = IntentIntegrator.forFragment(this);
        qrScanIntegrator.setOrientationLocked(false);

        // Different Customization option...
        qrScanIntegrator.setPrompt(getString(R.string.scan_a_code));
        qrScanIntegrator.setCameraId(0);  // Use a specific camera of the device
        qrScanIntegrator.setBeepEnabled(false);
        qrScanIntegrator.setBarcodeImageEnabled(true);

        super.onViewCreated(view, savedInstanceState);
    }

    private void performAction() {
        qrScanIntegrator.initiateScan();
    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data) {
        IntentResult result = IntentIntegrator.parseActivityResult(requestCode, resultCode, data);
        if (result != null) {
            // If QRCode has no data.
            if (result.getContents() == null) {
                Toast.makeText(getActivity(), R.string.result_not_found, Toast.LENGTH_LONG).show();
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
                    Toast.makeText(getActivity(), result.getContents(), Toast.LENGTH_LONG).show();
                }
            }
        } else {
            super.onActivityResult(requestCode, resultCode, data);
        }
    }
}
