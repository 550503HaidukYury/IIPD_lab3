package sample;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.List;

import javafx.animation.AnimationTimer;
import javafx.application.Application;
import javafx.beans.property.LongProperty;
import javafx.beans.property.SimpleLongProperty;
import javafx.fxml.FXMLLoader;
import javafx.geometry.Orientation;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.layout.FlowPane;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class Main extends Application {
    Label batteryFlag = new Label();
    Label aclineStatus = new Label();
    Label batteryLife = new Label();
    Label batteryLeft = new Label();
    Label batteryFull = new Label();
    Button run_prog = new Button("change delay display sleep");
    TextArea unput_area = new TextArea();
    Label runResult = new Label();
    Button set_delay = new Button("apply");


    @Override public void start(Stage primaryStage) throws Exception {
        StackPane menu = new StackPane();
        primaryStage.setTitle("Battery_Info");
        primaryStage.setScene(new Scene(menu, 300, 275));
        primaryStage.show();
        primaryStage.setResizable(true);
        FlowPane horFlowPane = new FlowPane();
        unput_area.setPrefSize(100,50);
        horFlowPane.getChildren()
            .addAll(batteryFlag, aclineStatus, batteryLife, batteryLeft, batteryFull,unput_area,run_prog,runResult,set_delay);
        horFlowPane.setOrientation(Orientation.VERTICAL);
        menu.getChildren().add(horFlowPane);
        final LongProperty lastUpdate = new SimpleLongProperty();
        final long minUpdateInterval = 2100000000 ; // nanoseconds. Set to higher number to slow output.

        run_prog.setOnAction(e -> {
            try {
                Runtime.getRuntime().exec("cmd /C " +unput_area.getText());
            } catch (IOException e1) {
                e1.printStackTrace();
                runResult.setText("'Can'not execute: '"+"delay_change.exe"+e1.getLocalizedMessage());
            }
        });
        //for_button-changer
        String myJarPath = Main.class.getProtectionDomain().getCodeSource().getLocation().getPath();
        String dirPath = new File(myJarPath).getParent();
        runResult.setText(dirPath);
        set_delay.setOnAction(e->{
            try {
                int valueDelay= Integer.parseInt(unput_area.getText());
                String arg1= String.valueOf(valueDelay);
                runResult.setText(dirPath);
                Runtime.getRuntime().exec("cmd /C" +dirPath+"\\delay_change.exe"+' '+arg1);
            }
            catch(java.io.IOException er) {
                System.out.println("'Can'not execute: '"+"delay_change.exe");
            }
        });


        /*
        try {
            //Runtime.getRuntime().exec("cmd /C " + fileName);
            //"cmd.exe /C \"\"c:\\program files\\winrar\\rar.exe\" param1 param2 \""
            runResult.setText(dirPath);
            Runtime.getRuntime().exec("cmd /C" +dirPath+"+\\delay_change.exe");
            //если все равно глючит хрень ниже надо раскомментировать
            //p.getInputStream().close();
            //p.getOutputStream().close();
            //p.getErrorStream().close();
        }
        catch(java.io.IOException e) {
            System.out.println("'Can'not execute: '"+"delay_change.exe");
        }
        */


        AnimationTimer timer = new AnimationTimer() {
            @Override
            public void handle(long now) {
                if (now - lastUpdate.get() > minUpdateInterval) {
                    ThreadUpdater thread =
                        new ThreadUpdater(batteryFlag, aclineStatus, batteryLife, batteryLeft, batteryFull);
                    thread.run();
                    lastUpdate.set(now);
                    try {
                        thread.join();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }

        };
        timer.start();

    }
    public void set_delay(int val1){
        try {
            String myJarPath = Main.class.getProtectionDomain().getCodeSource().getLocation().getPath();
            String dirPath = new File(myJarPath).getParent();
            String arg1 = null;
            switch(val1){
                case 1:
                    arg1= String.valueOf(10);
                    break;
                case 2:
                    arg1=String.valueOf(900);
                    break;
            }
            Runtime.getRuntime().exec("cmd /C" +dirPath+"\\delay_change.exe"+' '+arg1);
        }
        catch(java.io.IOException er) {
            System.out.println("'Can'not execute: '"+"delay_change.exe");
        }
    }
}

class ThreadUpdater extends Thread {
    Label batteryFlag=new Label();
    Label aclineStatus=new Label();
    Label batteryLife=new Label();
    Label batteryLeft=new Label();
    Label batteryFull=new Label();
    public ThreadUpdater(Label batteryFlag, Label aclineStatus,Label batteryLife,Label batteryLeft,Label batteryFull) {
        this.batteryFlag=batteryFlag;
        this.aclineStatus=aclineStatus;
        this.batteryLife=batteryLife;
        this.batteryLeft=batteryLeft;
        this.batteryFull=batteryFull;
    }

    public void run() {
        Kernel32.SYSTEM_POWER_STATUS batteryStatus = new Kernel32.SYSTEM_POWER_STATUS();
        Kernel32.INSTANCE.GetSystemPowerStatus(batteryStatus);
        batteryFlag.setText("battery status:"+batteryStatus.getBatteryFlagString());
        aclineStatus.setText("AC/battery: "+batteryStatus.getACLineStatusString());
        batteryLife.setText("battery life: "+batteryStatus.getBatteryLifePercent());
        batteryLeft.setText("battery Left: "+batteryStatus.getBatteryLifeTime());
        batteryFull.setText("battery Full: "+batteryStatus.getBatteryFullLifeTime());
        Main value=new Main();
        switch(batteryStatus.getACLineStatusString()){
            case "Online":
                value.set_delay(2);
                break;
            case "Offline":
                value.set_delay(1);
                break;
            default:
                break;
        }
    }
}


