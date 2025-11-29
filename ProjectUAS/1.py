# Jalankan kode ini sbelum menjalankan kode3_1
#Kode_sigma

def sigma(i,n):
  s=0
  for k in range(i,n):
    a=f(k)
    print('suku ke-',k,' adalah ',a)
    s=s+a
    k=k+1
  return s


# Jalankan kode program berikut
# Kode3_1

def f(i):
  return i

n = 10

def f(i):
    return (3*i + 2) / (n**2)


hasilSigma2 = sigma(1, n+1)
print("Hasilnyaa adalah:", hasilSigma2)
