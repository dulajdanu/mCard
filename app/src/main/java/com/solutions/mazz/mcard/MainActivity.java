package com.solutions.mazz.mcard;

import android.Manifest;
import android.content.ClipData;
import android.content.ClipboardManager;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.provider.DocumentsContract;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.telephony.SmsManager;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;


import com.firebase.ui.auth.AuthUI;
import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.OnFailureListener;
import com.google.android.gms.tasks.OnSuccessListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.firestore.CollectionReference;
import com.google.firebase.firestore.DocumentReference;
import com.google.firebase.firestore.DocumentSnapshot;
import com.google.firebase.firestore.FirebaseFirestore;
import com.google.firebase.firestore.QueryDocumentSnapshot;
import com.google.firebase.firestore.QuerySnapshot;
import com.google.zxing.integration.android.IntentIntegrator;
import com.google.zxing.integration.android.IntentResult;

import java.util.HashMap;
import java.util.Map;

public class MainActivity extends AppCompatActivity {

    private Button scanButton;
    private Button newStdentButton;
    public TextView textView;
    private String numOfTheStudent ;
    private String hasStudentPaid;
    private Button signoutb;
    private Button testBtn;

    private Button mailButn;

    private FirebaseAuth mFireBaseAuth;
    private FirebaseAuth.AuthStateListener mAuthStateListener;
    private static final int RC_SIGN_IN = 123;


    public final int my_per = 1;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        if(checkSmsPer(Manifest.permission.SEND_SMS))
        {

        }
        else {
            ActivityCompat.requestPermissions(this,new String[]{Manifest.permission.SEND_SMS},my_per);
        }



        scanButton  = findViewById(R.id.scanButton);
        textView = findViewById(R.id.mainText);
        newStdentButton = findViewById(R.id.newStudent);
        mailButn = findViewById(R.id.Mailbutton);

        mFireBaseAuth = FirebaseAuth.getInstance();

        signoutb = findViewById(R.id.signOutBt);
        testBtn = findViewById(R.id.Testbutton);
        scanButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                IntentIntegrator intentIntegrator = new IntentIntegrator(MainActivity.this);
                intentIntegrator.setDesiredBarcodeFormats(IntentIntegrator.QR_CODE_TYPES);
                intentIntegrator.setCameraId(0);
                intentIntegrator.setOrientationLocked(false);
                intentIntegrator.setPrompt("scanning");
                intentIntegrator.setBeepEnabled(true);
                intentIntegrator.setBarcodeImageEnabled(true);
                intentIntegrator.initiateScan();
            }
        });

        newStdentButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity.this,addNewStudent.class);
                startActivity(intent);
            }
        });

        signoutb.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                AuthUI.getInstance().signOut(MainActivity.this);
            }
        });


        mAuthStateListener = new FirebaseAuth.AuthStateListener() {
            @Override
            public void onAuthStateChanged(@NonNull FirebaseAuth firebaseAuth) {
                FirebaseUser user = firebaseAuth.getCurrentUser();
                if(user != null)
                {
                    Toast.makeText(MainActivity.this,"You Are Signed in",Toast.LENGTH_SHORT).show();
                    onSignedInInitialize(user.getDisplayName());
                }
                else
                {
                    onSignedOutClean();
                    startActivityForResult(
                            AuthUI.getInstance()
                                    .createSignInIntentBuilder()
                                    .setIsSmartLockEnabled(false)
                                    .setTheme(R.style.LoginTheme)
                                    .setAvailableProviders(Arrays.asList(
                                            new AuthUI.IdpConfig.GoogleBuilder().build(),
                                            new AuthUI.IdpConfig.EmailBuilder().build()
                                            ))
                                    .build(),
                            RC_SIGN_IN);
                }
            }
        };

        testBtn.setOnClickListener(new View.OnClickListener() {


            @Override
            public void onClick(View v) {
                //onSend();
                checkAbsent();
                sendSmsForStudents();
                final FirebaseFirestore dbnew = FirebaseFirestore.getInstance();
                dbnew.collection("Students")
                        .get()
                        .addOnCompleteListener(new OnCompleteListener<QuerySnapshot>() {
                            @Override
                            public void onComplete(@NonNull Task<QuerySnapshot> task) {
                                if (task.isSuccessful()) {
                                    for (QueryDocumentSnapshot document : task.getResult()) {
                                        //Log.d(TAG, document.getId() + " => " + document.getData());
                                        //textView.setText(document.getId());

//                                        dbnew.collection("puka").document(document.getId()).set(document);
                                    }
                                } else {
                                    //Log.d(TAG, "Error getting documents: ", task.getException());
                                }
                            }
                        });

            }
        });





    }

    public void checkAbsent()
    {
        final ArrayList<String> all = new ArrayList<String>();
        final FirebaseFirestore dbnew = FirebaseFirestore.getInstance();
        CollectionReference Allstudents = dbnew.collection("Students");

        Allstudents.get().addOnCompleteListener(new OnCompleteListener<QuerySnapshot>() {
            @Override
            public void onComplete(@NonNull Task<QuerySnapshot> task) {
                if(task.isSuccessful())
                {
                    for (DocumentSnapshot ds : task.getResult())
                    {
                        //all.add(ds.getString("phoneOfStu"));
                        dbnew.collection("ass").document(ds.getId()).set(ds);
                    }
                }
                else
                {
                    Toast.makeText(MainActivity.this, "Error", Toast.LENGTH_SHORT).show();
                }
            }
        });

        String date1 = new SimpleDateFormat("dd-MM-yyyy").format(new Date());
        CollectionReference PresentStudents = dbnew.collection("Present_student").document(date1).collection("TODAY_PRESENT");

        PresentStudents.get().addOnCompleteListener(new OnCompleteListener<QuerySnapshot>() {
            @Override
            public void onComplete(@NonNull Task<QuerySnapshot> task) {
                if(task.isSuccessful())
                {
                    for (DocumentSnapshot ds : task.getResult())
                    {
                        //all.remove(ds.getString("phoneOfStu"));
                        //all.add(ds.getString("phoneOfStu"));
                        //dbnew.collection("asses").document(ds.getId()).set(ds);
                        //String temp = ds.getString("phoneOfStu");
                        dbnew.collection("ass").document(ds.getId()).delete()
                                .addOnSuccessListener(new OnSuccessListener<Void>() {
                                    @Override
                                    public void onSuccess(Void aVoid) {
                                        Toast.makeText(MainActivity.this, "DocumentSnapshot successfully deleted!", Toast.LENGTH_SHORT).show();
                                        //Log.d(TAG, "DocumentSnapshot successfully deleted!");
                                    }
                                })
                                .addOnFailureListener(new OnFailureListener() {
                                    @Override
                                    public void onFailure(@NonNull Exception e) {
                                        //Log.w(TAG, "Error deleting document", e);
                                        Toast.makeText(MainActivity.this, "Error in deleting", Toast.LENGTH_SHORT).show();
                                    }
                                });


                    }
                }
                else
                {
                    Toast.makeText(MainActivity.this, "Error", Toast.LENGTH_SHORT).show();
                }
            }
        });

    }


    public void sendMailTo()
    {

    }

    public void sendSmsForStudents()
    {
        final FirebaseFirestore dbnew = FirebaseFirestore.getInstance();
        CollectionReference Allstudents = dbnew.collection("ass");
        //dbnew.collection("ass");

        Allstudents.get().addOnCompleteListener(new OnCompleteListener<QuerySnapshot>() {
            @Override
            public void onComplete(@NonNull Task<QuerySnapshot> task) {
                if(task.isSuccessful())
                {
                    for (DocumentSnapshot ds : task.getResult())
                    {
                        //all.remove(ds.getString("phoneOfStu"));
                        //all.add(ds.getString("phoneOfStu"));
                        //dbnew.collection("asses").document(ds.getId()).set(ds);
                        //String temp = ds.getString("phoneOfStu");
                        if(checkSmsPer(Manifest.permission.SEND_SMS))
                        {
                            SmsManager smsManager = SmsManager.getDefault();
                            smsManager.sendTextMessage(ds.getId(),null,"hi",null,null);
                            Toast.makeText(MainActivity.this, "Message sent ", Toast.LENGTH_SHORT).show();
                        }
                        else
                        {
                            //Toast.makeText(this,"Permission denied",Toast.LENGTH_LONG).show();
                            Toast.makeText(MainActivity.this, "Permission denied", Toast.LENGTH_SHORT).show();
                        }



                    }
                }
                else
                {
                    Toast.makeText(MainActivity.this, "Error", Toast.LENGTH_SHORT).show();
                }
            }
        });

    }







    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable final Intent data) {
        final IntentResult result = IntentIntegrator.parseActivityResult(requestCode,resultCode,data);
        if(result!=null && result.getContents() != null)
        {


            numOfTheStudent = result.getContents();
            numOfTheStudent = numOfTheStudent.replace("\n","");
            final FirebaseFirestore db = FirebaseFirestore.getInstance();

            CollectionReference sturef = db.collection("Students");
            final DocumentReference docref = sturef.document(numOfTheStudent);
            docref.get().addOnCompleteListener(new OnCompleteListener<DocumentSnapshot>() {
                @Override
                public void onComplete(@NonNull Task<DocumentSnapshot> task) {
                    if (task.isSuccessful()) {
                        DocumentSnapshot document = task.getResult();
                        if (document.exists()) {


                            hasStudentPaid = document.get("hasPaid").toString();
                            if(hasStudentPaid.equalsIgnoreCase("true"))
                            {
                                //Toast.makeText(MainActivity.this, document.get("nameOfStu").toString() + " has paid", Toast.LENGTH_LONG).show();
                                textView.setText(document.get("nameOfStu").toString() + " has paid");
                                Date date = new Date();
                                SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");
                                Map<String, Object> student = new HashMap<>();
                                student.put("isPresent", "yes");
                                //DocumentReference dref = db.collection("Present_Students").document(numOfTheStudent);
                                //dref.set(student);
                                //db.collection("Students").document("PresentStu").set(student);
                                //String currdate = formatter.format(date);
                                String date1 = new SimpleDateFormat("dd-MM-yyyy").format(new Date());

                                db.collection("Present_student").document(date1).collection("TODAY_PRESENT").document(numOfTheStudent).set(student);


                            }
                            else
                            {
                                //Toast.makeText(MainActivity.this,document.get("nameOfStu").toString() + " has not paid",Toast.LENGTH_LONG).show();
                                textView.setText(document.get("nameOfStu").toString() + " has  not paid");
                            }

                        } else {
                            Toast.makeText(MainActivity.this,"Student Not Found",Toast.LENGTH_LONG).show();
                        }
                    } else {
                        //Log.d(TAG, "get failed with ", task.getException());
                    }
                }
            });






        }

        super.onActivityResult(requestCode, resultCode, data);
    }

    @Override
    protected void onPause() {
        super.onPause();
        mFireBaseAuth.removeAuthStateListener(mAuthStateListener);
    }

    @Override
    protected void onResume() {
        super.onResume();
        mFireBaseAuth.addAuthStateListener(mAuthStateListener);
    }

    private void onSignedInInitialize(String userName)
    {

    }

    private void onSignedOutClean()
    {

    }

    public boolean checkSmsPer(String per)
    {
        int check = ContextCompat.checkSelfPermission(this,per);
        return (check==PackageManager.PERMISSION_GRANTED);
    }

//    public void onSend()
//    {
//        if(checkSmsPer(Manifest.permission.SEND_SMS))
//        {
//            SmsManager smsManager = SmsManager.getDefault();
//            smsManager.sendTextMessage("0776396993",null,"hi",null,null);
//            Toast.makeText(this,"Message sent ",Toast.LENGTH_LONG).show();
//        }
//        else
//        {
//            Toast.makeText(this,"Permission denied",Toast.LENGTH_LONG).show();
//
//        }
//    }

}


