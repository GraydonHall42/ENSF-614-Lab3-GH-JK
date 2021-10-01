void DynString::append(const DynString& tail){
  int new_length = lengthM + tail.lengthM;  // find new length
  char * holder;  // char array to hold our new string
  holder = new char[new_length];  // add 1 to length to account for '\0'
  strcpy(holder, storageM);  // copy starageM contents into holder first

  // copy contents of tail into holder
  for (int i = 0; i < tail.lengthM; i++) {
    holder[i+lengthM] = tail.storageM[i];
  }

  holder[new_length] = '\0';
  storageM = holder;
  lengthM = new_length;
}