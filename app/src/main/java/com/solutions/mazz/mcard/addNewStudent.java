package com.solutions.mazz.mcard;

import android.support.annotation.NonNull;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.OnFailureListener;
import com.google.android.gms.tasks.OnSuccessListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.firestore.CollectionReference;
import com.google.firebase.firestore.DocumentReference;
import com.google.firebase.firestore.DocumentSnapshot;
import com.google.firebase.firestore.FirebaseFirestore;
import com.google.firebase.firestore.Query;
import com.google.firebase.firestore.QueryDocumentSnapshot;
import com.google.firebase.firestore.QuerySnapshot;
import com.google.firebase.firestore.SetOptions;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Date;
import java.time.LocalDate;

public class addNewStudent extends AppCompatActivity {

    private EditText nameOfStudent;
    private EditText schoolOfStudent;
    private EditText phoneNumOfStu;
    private Button addStudentButtn;
    private Button updateBtn;
    ArrayList<String> arrli = new ArrayList<>();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_new_student);

        nameOfStudent = findViewById(R.id.nameText);
        schoolOfStudent = findViewById(R.id.schoolText);
        phoneNumOfStu = findViewById(R.id.phoneNum);
        addStudentButtn = findViewById(R.id.addNewStudentButton);
        updateBtn = findViewById(R.id.updateButton);

        addStudentButtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //Map<String, Object> user = new HashMap<>();
                //user.put("text","" + nameOfStudent.getText().toString()+schoolOfStudent.getText().toString()+phoneNumOfStu.getText().toString() );
                final FirebaseFirestore db = FirebaseFirestore.getInstance();
                //CollectionReference students = db.collection("Students");
                String name = nameOfStudent.getText().toString();
                String school = schoolOfStudent.getText().toString();
                final  String number = phoneNumOfStu.getText().toString();

                final Date date = new Date();
                final SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");

                Map<String, Object> student = new HashMap<>();
                student.put("nameOfStu", name);
                student.put("schoolOfStu", school);
                student.put("phoneOfStu", number);
                student.put("daysAbsent","0");
                student.put("dateJoined",formatter.format(date));
                student.put("hasPaid",true);


                //db.collection("Students").document(number).collection("Absent").document(number).set(student);

                db.collection("Students").document(number)
                        .set(student)
                        .addOnSuccessListener(new OnSuccessListener<Void>() {
                            @Override
                            public void onSuccess(Void aVoid) {

                                //Log.d(TAG, "DocumentSnapshot successfully written!");
                                Map<String, Object> present = new HashMap<>();
                                present.put("isPresent","yes");
                                String date1 = new SimpleDateFormat("dd-MM-yyyy").format(new Date());
                                db.collection("Students").document(number).collection("ATTENDENCE").document(date1).set(present);

                                Toast.makeText(addNewStudent.this,"New Student Added",Toast.LENGTH_SHORT).show();
                                db.collection("Present_student").document(date1).collection("TODAY_PRESENT").document(number).set(present);
                                arrli.add(number);

                            }
                        })
                        .addOnFailureListener(new OnFailureListener() {
                            @Override
                            public void onFailure(@NonNull Exception e) {
                                //Log.w(TAG, "Error writing document", e);
                                Toast.makeText(addNewStudent.this,e.getMessage(),Toast.LENGTH_SHORT).show();


                            }
                        });




            }
        });



    }
}
