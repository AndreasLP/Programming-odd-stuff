final = imread('final.png');
working = im2double(final);
%imshow(log(working+1),[]);
figure(1);
subplot(2,2,1);
imshow(working);
mini = min(working,[],[1 2]);
maxi = max(working,[],[1 2]);
R = (working(:,:,1)-mini(1))/(maxi(1)-mini(1));
G = (working(:,:,2)-mini(2))/(maxi(2)-mini(2));
B = (working(:,:,3)-mini(3))/(maxi(3)-mini(3));
subplot(2,2,2);
imshow(R);
subplot(2,2,3);
imshow(G);
subplot(2,2,4);
imshow(B);
% 108 - l
% 115 - s
%  98 - b