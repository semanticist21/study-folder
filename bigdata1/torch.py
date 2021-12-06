import numpy as np
import torch
import torchvision
import torchvision.transforms as transforms
import torch.nn as nn
import torch.nn.functional as f
import torch.optim as optim
import matplotlib.pyplot as plt

device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")

test_transform = transforms.Compose(
    [transforms.ToTensor(),
     transforms.Normalize((0.5, 0.5, 0.5), (0.5, 0.5, 0.5))])

##Data Augmentation##
train_transform = transforms.Compose([
    transforms.RandomHorizontalFlip(),
    transforms.RandomVerticalFlip(),
    transforms.ColorJitter(brightness=0.5),
    transforms.RandomAffine(degrees=40),
    transforms.ToTensor(),
    transforms.Normalize((0.5, 0.5, 0.5), (0.5, 0.5, 0.5))
    ])

test_set=torchvision.datasets.CIFAR10(root='./data', train=False, download=True, transform=test_transform)
test_loader = torch.utils.data.DataLoader(test_set, batch_size = 4, shuffle=False, num_workers = 2)

train_set=torchvision.datasets.CIFAR10(root='./data', train=True, download=True, transform=train_transform)
train_loader = torch.utils.data.DataLoader(train_set, batch_size = 4, shuffle=False, num_workers = 2)

classes = ('plane', 'car', 'bird', 'cat',
           'deer', 'dog', 'frog', 'horse', 'ship', 'truck')

class Convolutial_Net(nn.Module):
  def __init__(model):
    super(Convolutial_Net, model).__init__()
    
    model.conv1 = nn.Conv2d(3,84,kernel_size=7,stride=1,padding=2)
    model.conv1_BN = nn.BatchNorm2d(84)
    model.pooling1 = nn.MaxPool2d(3,1)
    
    model.conv2 = nn.Conv2d(84,250,kernel_size=7,stride=1,padding=2)
    model.conv2_BN = nn.BatchNorm2d(250)
    model.pooling2 = nn.MaxPool2d(3,2)
    
    model.conv3 = nn.Conv2d(250,375,kernel_size=5,stride=1,padding=2)
    model.conv3_BN = nn.BatchNorm2d(375)
    
    model.conv4 = nn.Conv2d(375,375,kernel_size=3,stride=1,padding=2)
    model.conv4_BN = nn.BatchNorm2d(375)
    
    model.conv5 = nn.Conv2d(375,250,kernel_size=3,stride=1,padding=2)
    model.conv5_BN = nn.BatchNorm2d(250)
    model.pooling3 = nn.MaxPool2d(3,2)
    
    model.fc1 = nn.Linear(7*7*250,4096)            ##여기 64000 값을 좀 줄일 수 있도록 Model 구성해야함
    model.fc1_BN = nn.BatchNorm1d(4096)
    
    model.fc2 = nn.Linear(4096,1024)
    model.fc2_BN = nn.BatchNorm1d(1024)
    
    model.fc3 = nn.Linear(1024,10)  #classification 10 kinds of image
    
    model.dp = nn.Dropout(p=0.5)
    
  def forward(model,x):
      x = model.pooling1(f.relu(model.conv1_BN(model.conv1(x))))
      x = model.pooling2(f.relu(model.conv2_BN(model.conv2(x))))
      
      x = f.relu(model.conv3_BN(model.conv3(x)))
      x = f.relu(model.conv4_BN(model.conv4(x)))
      x= model.pooling3(f.relu(model.conv5_BN(model.conv5(x))))
      
      
      ##Making Fully Connection and dropout
      x = x.view(x.size(0),-1)  
      x = model.dp(x)
      
      x = f.relu(model.fc1_BN(model.fc1(x)))
      x = model.dp(x)
      
      x = f.relu(model.fc2_BN(model.fc2(x)))
      x = model.dp(x)
      
      x = f.log_softmax(model.fc3(x), dim = 0)
      
      return x  
      
net =  Convolutial_Net().to(device)       
##initializing weights with HeNormal##      
def init_weights(module) : 
    
    if isinstance(module, nn.Conv2d):
        torch.nn.init.kaiming_uniform_(module.weight)
        torch.nn.init.kaiming_uniform_(module.bias)
        
    elif isinstance(module, nn.BatchNorm1d):
        torch.nn.init.kaiming_uniform_(module.weight)
        torch.nn.init.kaiming_uniform_(module.bias)
             
    elif isinstance(module, nn.BatchNorm2d):
        torch.nn.init.kaiming_uniform_(module.weight)
        torch.nn.init.kaiming_uniform_(module.bias)
    
    elif isinstance(module, nn.Linear):
        torch.nn.init.kaiming_uniform_(module.weight)    
        torch.nn.init.kaiming_uniform_(module.bias)         
        
  
init_weights(net)
criterion = nn.CrossEntropyLoss()
optimizer = optim.AdamW(net.parameters(),lr=0.1)

epoch_loss_list=[]
epoch_acc_list=[]
valid_loss_list=[]
valid_acc_list=[]


##Training our net##
for epoch in range(100):   # 데이터셋을 수차례 반복합니다.

    running_loss = 0.0
    running_acc = 0.0
    valid_loss = 0.0
    valid_acc = 0.0
    epoch_loss=0.0
    epoch_acc = 0.0


    net.train()
    for i, data in enumerate(train_loader, 0):
        # [inputs, labels]의 목록인 data로부터 입력을 받은 후;
        inputs, labels = data[0].to(device), data[1].to(device)

        # 변화도(Gradient) 매개변수를 0으로 만들고
        optimizer.zero_grad()

        # 순전파 + 역전파 + 최적화를 한 후
        outputs = net(inputs)
        loss = criterion(outputs, labels)
        acc = (outputs.argmax(axis=1)==labels).float().sum()/10
        loss.backward()
        optimizer.step()

        # 통계를 출력합니다.
        running_loss += loss.item()
        running_acc += acc.item()
        if i % 10 == 9:    # print every 10 mini-batches
            print('[%d, %5d] loss: %.3f acc: %.3f' %
                  (epoch + 1, i + 1, running_loss / 10, running_acc/10))
            running_loss = 0.0
            running_acc = 0.0
            
    print('[%d, %5d] Finish loss : %.3f acc: %.3f' %(
        epoch+1, i+1, epoch_loss / (i+1), epoch_acc / (i+1)
    ))
    
    epoch_loss_list.append(epoch_loss/(i+1))
    epoch_acc_list.append(epoch_acc/(i+1))
    epoch_loss = 0.0
    epoch_acc =0.0
    net.eval()
    
    for i, data in enumerate(test_loader,0):
        inputs, labels = data[0].to(device), data[1].to(device)

        
        optimizer.zero_grad()
        outputs = net(inputs)
        loss = criterion(outputs, labels)
        acc = (outputs.argmax(axis=1)==labels).float().sum()/10
        valid_loss+=loss.item()
        valid_acc +=acc.item()
        
    print('[%d, %5d] Valid loss : %.3f acc: %.3f \n' %(
        epoch+1, i+1, valid_loss / (i+1), valid_acc / (i+1)
    ))    
    
    valid_loss_list.append(valid_loss/(i+1))
    valid_acc_list.append(valid_acc/(i+1))
    
print('Finished Training')    