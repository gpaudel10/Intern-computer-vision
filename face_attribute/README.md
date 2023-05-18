- [Image classification from scratch.](#image-classification-from-scratch)
  - [Requirements:](#requirements)
  - [Overview](#overview)
  - [Works done](#works-done)
  - [Conclusion](#conclusion)

## Image classification from scratch.

### Requirements:

* Use a custom dataset.
* Write a custom dataloader.
* Write a train/valid pipeline that can save and load    checkpoints. Make sure to record each epoch's training and
validation logs, and then plot the logs.
* Write an inference pipeline that can be used to infer a single image.
 ---

### Overview 
First of all there are three notebook files attached herewith `face_attributemobilenet.ipynb`,`facee.ipynb` and `face_attribute.ipynb` where,

1. `face_attributemobilenet.ipynb` only has some praticed codes,
2. `facee.ipynb` is the main file and
3. `face_attribute.ipynb` is where i practice saving the checkpoints.

### Works done
In this task i have learned about image classifier using custom dataset, to build the model, to train the model in existing pretrained model(in mobilenet_v3_small).

In `facee.ipynb`, custom dataset having 5 classes [good,oclusion,hat,smile,glass] is used. They are transformed and augmented with some degree rotation, horizontal fliping and normalized with standard mean and deviation. After that train and test dataset is loaded in ImageFolder of pytorch. Then DataLoader is created with the batch_size of 32. And some images(of one batch) is obsereved using matplotlib and numpy. After that i have build model with three different ways:
1. build the custom cnn module with 3 layers and containing two fully connected layers giving out 5 output features for the 5 classes.
2. trained with pretrained module mobilenet_v3_small(also tried v3_large just to see)
3. sliced the last fullyconnected layer of mobilenet and by freezing its layers and trained our datasets. It also gives the accuracy of 89% one time but started to overfitt while adjusting the hyperparameters and retraining the model (also tried by early stopping and l1 and l2 regularization for better accuracy but could not implement being very new to pytorch and lot to learn).
4. I also tried to plot the training and validation plot.
5. And at last i tried to infer the single image by giving path to the model and to predict with the help of PIL and unsqueeze function and model predicts correctly.

Here I have commented the models mentioned in 1 and 2 and be checked by uncommenting.

At last in `face_attribute.ipynb` i have tried to implement the checkpoints to save and load the model, epochs, optimizer,best_accuracy_epoch etc as needed but i have only tried to save the model of 5th epoch just to pratciced. Model is saved succesfully with .pth extension but could not load.

### Conclusion

Overall learned about the custom building of models and how we can modify the pretrained model as we needs and train our model also basics to plot and saving the best models as well as about classes and functions of pytorch. 




