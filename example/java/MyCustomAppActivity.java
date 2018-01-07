package org.qtproject.example;

import org.pwf.qtonesignal.QOneSignalBinding;
import android.os.Bundle;

public class MyCustomAppActivity extends org.qtproject.qt5.android.bindings.QtActivity {
    @Override
    public void onCreate(Bundle bundle) {
        super.onCreate(bundle);
        QOneSignalBinding.onCreate(this, bundle);
    }
}
