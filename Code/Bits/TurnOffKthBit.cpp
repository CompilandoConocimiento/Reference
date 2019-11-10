int toogle_off_bit(int number, int place) { 
  return (number bitand ~(1 << place)); 
}
