# Load3DMap Cluster Resolution

This resolves the previously ambiguous Ghidra nearest-function cluster around the `Load3DMap` string.

## Resolution

- The `Load3DMap` text anchor is embedded string/data, not a function entry.
- The loader-shaped code window is payload `0x30AD0-0x30C10`.
- `3000:0c04` is a misaligned Ghidra entry inside the epilogue instruction, not an empty loader function.
- `3000:006f` remains a wall/span emit candidate, not the `Load3DMap` loader.

## Facts

- `load3dmap_anchor_is_string_data` (99%): Raw disassembly at 0x30AAF-0x30ACF decodes ASCII bytes for 'Unable to load geo in Load3DMap.'; instruction mnemonics there are ASCII-as-code artifacts.
- `post_string_code_is_loader_shaped` (90%): Code resumes at 0x30AD0 with a stack frame, builds GEO filename text, checks loaded size 0x402, copies four 0x100-byte chunks from global buffer 0x7360, closes/releases the loaded buffer, and writes the selected map byte to active state at *(0x4418)+0xC5.
- `ghidra_3000_0c04_is_misaligned_epilogue` (99%): Ghidra entry 3000:0c04 maps to payload 0x30C04, which is inside instruction '26 88 85 c5 00' beginning at 0x30C01; the actual epilogue is 0x30C06-0x30C10.
- `ghidra_3000_006f_not_load3dmap` (85%): 3000:006f remains a behavior-rich wall/span emit candidate, but the raw Load3DMap-shaped loader code is at 0x30AD0-0x30C10, after the embedded error string.

## Key Disassembly Windows

### pre_string_loader_code

```asm
   3091c:	0e                   	push   cs
   3091d:	57                   	push   di
   3091e:	9a c2 0a c0 0c       	call   0xcc0:0xac2
   30923:	8d 7e ee             	lea    di,[bp-0x12]
   30926:	16                   	push   ss
   30927:	57                   	push   di
   30928:	9a 4f 0b c0 0c       	call   0xcc0:0xb4f
   3092d:	8d be e8 fe          	lea    di,[bp-0x118]
   30931:	16                   	push   ss
   30932:	57                   	push   di
   30933:	bf a5 0e             	mov    di,0xea5
   30936:	0e                   	push   cs
   30937:	57                   	push   di
   30938:	9a c2 0a c0 0c       	call   0xcc0:0xac2
   3093d:	8a 46 08             	mov    al,BYTE PTR [bp+0x8]
   30940:	50                   	push   ax
   30941:	8d 7e fe             	lea    di,[bp-0x2]
   30944:	16                   	push   ss
   30945:	57                   	push   di
   30946:	8d 7e fa             	lea    di,[bp-0x6]
   30949:	16                   	push   ss
   3094a:	57                   	push   di
   3094b:	9a e8 08 8b 07       	call   0x78b:0x8e8
   30950:	83 7e fe 00          	cmp    WORD PTR [bp-0x2],0x0
   30954:	74 18                	je     0x3096e
   30956:	8a 46 06             	mov    al,BYTE PTR [bp+0x6]
   30959:	30 e4                	xor    ah,ah
   3095b:	8b d8                	mov    bx,ax
   3095d:	8b 46 fe             	mov    ax,WORD PTR [bp-0x2]
   30960:	31 d2                	xor    dx,dx
   30962:	b9 0c 03             	mov    cx,0x30c
   30965:	f7 f1                	div    cx
   30967:	03 c3                	add    ax,bx
   30969:	3d 04 00             	cmp    ax,0x4
   3096c:	76 6b                	jbe    0x309d9
   3096e:	9a dd 00 1a 02       	call   0x21a:0xdd
   30973:	bf 4e a0             	mov    di,0xa04e
   30976:	1e                   	push   ds
   30977:	57                   	push   di
   30978:	bf aa 0e             	mov    di,0xeaa
   3097b:	0e                   	push   cs
   3097c:	57                   	push   di
   3097d:	31 c0                	xor    ax,ax
   3097f:	50                   	push   ax
   30980:	9a 17 09 c0 0c       	call   0xcc0:0x917
   30985:	8a 46 08             	mov    al,BYTE PTR [bp+0x8]
   30988:	30 e4                	xor    ah,ah
   3098a:	31 d2                	xor    dx,dx
   3098c:	52                   	push   dx
   3098d:	50                   	push   ax
   3098e:	31 c0                	xor    ax,ax
   30990:	50                   	push   ax
   30991:	9a ad 09 c0 0c       	call   0xcc0:0x9ad
   30996:	8d be ed fe          	lea    di,[bp-0x113]
   3099a:	16                   	push   ss
   3099b:	57                   	push   di
   3099c:	bf ba 0e             	mov    di,0xeba
   3099f:	0e                   	push   cs
   309a0:	57                   	push   di
   309a1:	9a c2 0a c0 0c       	call   0xcc0:0xac2
   309a6:	8d 7e ee             	lea    di,[bp-0x12]
   309a9:	16                   	push   ss
   309aa:	57                   	push   di
   309ab:	9a 4f 0b c0 0c       	call   0xcc0:0xb4f
   309b0:	bf c8 0e             	mov    di,0xec8
   309b3:	0e                   	push   cs
   309b4:	57                   	push   di
   309b5:	9a 4f 0b c0 0c       	call   0xcc0:0xb4f
   309ba:	31 c0                	xor    ax,ax
   309bc:	50                   	push   ax
   309bd:	9a 17 09 c0 0c       	call   0xcc0:0x917
   309c2:	9a 48 08 c0 0c       	call   0xcc0:0x848
   309c7:	9a c7 01 36 08       	call   0x836:0x1c7
   309cc:	88 46 ed             	mov    BYTE PTR [bp-0x13],al
   309cf:	9a dd 00 1a 02       	call   0x21a:0xdd
   309d4:	9a 00 00 36 08       	call   0x836:0x0
   309d9:	8a 46 06             	mov    al,BYTE PTR [bp+0x6]
   309dc:	30 e4                	xor    ah,ah
   309de:	8b f8                	mov    di,ax
   309e0:	d1 e7                	shl    di,1
   309e2:	8b 85 ae 26          	mov    ax,WORD PTR [di+0x26ae]
   309e6:	2b 06 b0 26          	sub    ax,WORD PTR ds:0x26b0
   309ea:	89 46 f6             	mov    WORD PTR [bp-0xa],ax
   309ed:	31 c0                	xor    ax,ax
   309ef:	89 46 f8             	mov    WORD PTR [bp-0x8],ax
   309f2:	c7 46 f3 01 00       	mov    WORD PTR [bp-0xd],0x1
   309f7:	8b 46 f8             	mov    ax,WORD PTR [bp-0x8]
   309fa:	c4 7e fa             	les    di,DWORD PTR [bp-0x6]
   309fd:	03 f8                	add    di,ax
   309ff:	06                   	push   es
   30a00:	57                   	push   di
   30a01:	8a 46 06             	mov    al,BYTE PTR [bp+0x6]
   30a04:	30 e4                	xor    ah,ah
   30a06:	03 46 f3             	add    ax,WORD PTR [bp-0xd]
   30a09:	ba 0c 03             	mov    dx,0x30c
   30a0c:	f7 e2                	mul    dx
   30a0e:	c4 3e 5c 73          	les    di,DWORD PTR ds:0x735c
   30a12:	03 f8                	add    di,ax
   30a14:	81 c7 f4 fc          	add    di,0xfcf4
   30a18:	06                   	push   es
   30a19:	57                   	push   di
   30a1a:	b8 0c 03             	mov    ax,0x30c
   30a1d:	50                   	push   ax
   30a1e:	9a af 1a c0 0c       	call   0xcc0:0x1aaf
   30a23:	81 46 f8 0c 03       	add    WORD PTR [bp-0x8],0x30c
   30a28:	ff 46 f3             	inc    WORD PTR [bp-0xd]
   30a2b:	8b 46 f8             	mov    ax,WORD PTR [bp-0x8]
   30a2e:	3b 46 fe             	cmp    ax,WORD PTR [bp-0x2]
   30a31:	72 c4                	jb     0x309f7
   30a33:	ff 76 fc             	push   WORD PTR [bp-0x4]
   30a36:	ff 76 fa             	push   WORD PTR [bp-0x6]
   30a39:	ff 76 fe             	push   WORD PTR [bp-0x2]
   30a3c:	9a 54 02 c0 0c       	call   0xcc0:0x254
   30a41:	8b 46 f3             	mov    ax,WORD PTR [bp-0xd]
   30a44:	48                   	dec    ax
   30a45:	88 46 f0             	mov    BYTE PTR [bp-0x10],al
   30a48:	8a 46 08             	mov    al,BYTE PTR [bp+0x8]
   30a4b:	50                   	push   ax
   30a4c:	8a 46 06             	mov    al,BYTE PTR [bp+0x6]
   30a4f:	50                   	push   ax
   30a50:	9a 25 00 39 01       	call   0x139:0x25
   30a55:	c6 06 d7 9e 01       	mov    BYTE PTR ds:0x9ed7,0x1
   30a5a:	8a 46 08             	mov    al,BYTE PTR [bp+0x8]
   30a5d:	50                   	push   ax
   30a5e:	0e                   	push   cs
   30a5f:	e8 d2 fd             	call   0x30834
   30a62:	b0 20                	mov    al,0x20
   30a64:	50                   	push   ax
   30a65:	b8 94 00             	mov    ax,0x94
   30a68:	50                   	push   ax
   30a69:	bf c7 96             	mov    di,0x96c7
   30a6c:	1e                   	push   ds
   30a6d:	57                   	push   di
   30a6e:	9a fa 27 1a 02       	call   0x21a:0x27fa
   30a73:	8a 46 08             	mov    al,BYTE PTR [bp+0x8]
   30a76:	30 e4                	xor    ah,ah
   30a78:	8b d0                	mov    dx,ax
   30a7a:	8a 46 06             	mov    al,BYTE PTR [bp+0x6]
   30a7d:	30 e4                	xor    ah,ah
   30a7f:	8b f8                	mov    di,ax
   30a81:	d1 e7                	shl    di,1
   30a83:	d1 e7                	shl    di,1
   30a85:	89 95 6e 73          	mov    WORD PTR [di+0x736e],dx
   30a89:	8a 46 06             	mov    al,BYTE PTR [bp+0x6]
   30a8c:	30 e4                	xor    ah,ah
   30a8e:	8b d0                	mov    dx,ax
   30a90:	8a 46 06             	mov    al,BYTE PTR [bp+0x6]
   30a93:	30 e4                	xor    ah,ah
   30a95:	8b f8                	mov    di,ax
   30a97:	d1 e7                	shl    di,1
   30a99:	d1 e7                	shl    di,1
   30a9b:	89 95 70 73          	mov    WORD PTR [di+0x7370],dx
   30a9f:	89 ec                	mov    sp,bp
   30aa1:	5d                   	pop    bp
   30aa2:	ca 04 00             	retf   0x4
```

### embedded_load3dmap_strings

```asm
   30aa5:	03 47 45             	add    ax,WORD PTR [bx+0x45]
   30aa8:	4f                   	dec    di
   30aa9:	04 2e                	add    al,0x2e
   30aab:	64 61                	fs popa
   30aad:	78 20                	js     0x30acf
   30aaf:	55                   	push   bp
   30ab0:	6e                   	outs   dx,BYTE PTR ds:[si]
   30ab1:	61                   	popa
   30ab2:	62 6c 65             	bound  bp,DWORD PTR [si+0x65]
   30ab5:	20 74 6f             	and    BYTE PTR [si+0x6f],dh
   30ab8:	20 6c 6f             	and    BYTE PTR [si+0x6f],ch
   30abb:	61                   	popa
   30abc:	64 20 67 65          	and    BYTE PTR fs:[bx+0x65],ah
   30ac0:	6f                   	outs   dx,WORD PTR ds:[si]
   30ac1:	20 69 6e             	and    BYTE PTR [bx+di+0x6e],ch
   30ac4:	20 4c 6f             	and    BYTE PTR [si+0x6f],cl
   30ac7:	61                   	popa
   30ac8:	64 33 44 4d          	xor    ax,WORD PTR fs:[si+0x4d]
   30acc:	61                   	popa
   30acd:	70 2e                	jo     0x30afd
   30acf:	55                   	push   bp
```

### post_string_loader_code

```asm
   30ad0:	89 e5                	mov    bp,sp
   30ad2:	81 ec 10 01          	sub    sp,0x110
   30ad6:	a0 d2 50             	mov    al,ds:0x50d2
   30ad9:	30 e4                	xor    ah,ah
   30adb:	31 d2                	xor    dx,dx
   30add:	52                   	push   dx
   30ade:	50                   	push   ax
   30adf:	31 c0                	xor    ax,ax
   30ae1:	50                   	push   ax
   30ae2:	8d 7e f6             	lea    di,[bp-0xa]
   30ae5:	16                   	push   ss
   30ae6:	57                   	push   di
   30ae7:	b8 01 00             	mov    ax,0x1
   30aea:	50                   	push   ax
   30aeb:	9a 90 17 c0 0c       	call   0xcc0:0x1790
   30af0:	8d be f5 fe          	lea    di,[bp-0x10b]
   30af4:	16                   	push   ss
   30af5:	57                   	push   di
   30af6:	bf 86 10             	mov    di,0x1086
   30af9:	0e                   	push   cs
   30afa:	57                   	push   di
   30afb:	9a c2 0a c0 0c       	call   0xcc0:0xac2
   30b00:	8d 7e f6             	lea    di,[bp-0xa]
   30b03:	16                   	push   ss
   30b04:	57                   	push   di
   30b05:	9a 4f 0b c0 0c       	call   0xcc0:0xb4f
   30b0a:	8d be f0 fe          	lea    di,[bp-0x110]
   30b0e:	16                   	push   ss
   30b0f:	57                   	push   di
   30b10:	bf 8a 10             	mov    di,0x108a
   30b13:	0e                   	push   cs
   30b14:	57                   	push   di
   30b15:	9a c2 0a c0 0c       	call   0xcc0:0xac2
   30b1a:	8a 46 06             	mov    al,BYTE PTR [bp+0x6]
   30b1d:	50                   	push   ax
   30b1e:	8d 7e fe             	lea    di,[bp-0x2]
   30b21:	16                   	push   ss
   30b22:	57                   	push   di
   30b23:	8d 7e fa             	lea    di,[bp-0x6]
   30b26:	16                   	push   ss
   30b27:	57                   	push   di
   30b28:	9a e8 08 8b 07       	call   0x78b:0x8e8
   30b2d:	83 7e fe 00          	cmp    WORD PTR [bp-0x2],0x0
   30b31:	74 07                	je     0x30b3a
   30b33:	81 7e fe 02 04       	cmp    WORD PTR [bp-0x2],0x402
   30b38:	74 2e                	je     0x30b68
   30b3a:	9a dd 00 1a 02       	call   0x21a:0xdd
   30b3f:	bf 4e a0             	mov    di,0xa04e
   30b42:	1e                   	push   ds
   30b43:	57                   	push   di
   30b44:	bf 8f 10             	mov    di,0x108f
   30b47:	0e                   	push   cs
   30b48:	57                   	push   di
   30b49:	31 c0                	xor    ax,ax
   30b4b:	50                   	push   ax
   30b4c:	9a 17 09 c0 0c       	call   0xcc0:0x917
   30b51:	9a 48 08 c0 0c       	call   0xcc0:0x848
   30b56:	9a c7 01 36 08       	call   0x836:0x1c7
   30b5b:	88 46 f5             	mov    BYTE PTR [bp-0xb],al
   30b5e:	9a dd 00 1a 02       	call   0x21a:0xdd
   30b63:	9a 00 00 36 08       	call   0x836:0x0
   30b68:	c7 46 f8 02 00       	mov    WORD PTR [bp-0x8],0x2
   30b6d:	8b 46 f8             	mov    ax,WORD PTR [bp-0x8]
   30b70:	c4 7e fa             	les    di,DWORD PTR [bp-0x6]
   30b73:	03 f8                	add    di,ax
   30b75:	06                   	push   es
   30b76:	57                   	push   di
   30b77:	c4 3e 60 73          	les    di,DWORD PTR ds:0x7360
   30b7b:	06                   	push   es
   30b7c:	57                   	push   di
   30b7d:	b8 00 01             	mov    ax,0x100
   30b80:	50                   	push   ax
   30b81:	9a af 1a c0 0c       	call   0xcc0:0x1aaf
   30b86:	81 46 f8 00 01       	add    WORD PTR [bp-0x8],0x100
   30b8b:	8b 46 f8             	mov    ax,WORD PTR [bp-0x8]
   30b8e:	c4 7e fa             	les    di,DWORD PTR [bp-0x6]
   30b91:	03 f8                	add    di,ax
   30b93:	06                   	push   es
   30b94:	57                   	push   di
   30b95:	c4 3e 60 73          	les    di,DWORD PTR ds:0x7360
   30b99:	81 c7 00 01          	add    di,0x100
   30b9d:	06                   	push   es
   30b9e:	57                   	push   di
   30b9f:	b8 00 01             	mov    ax,0x100
   30ba2:	50                   	push   ax
   30ba3:	9a af 1a c0 0c       	call   0xcc0:0x1aaf
   30ba8:	81 46 f8 00 01       	add    WORD PTR [bp-0x8],0x100
   30bad:	8b 46 f8             	mov    ax,WORD PTR [bp-0x8]
   30bb0:	c4 7e fa             	les    di,DWORD PTR [bp-0x6]
   30bb3:	03 f8                	add    di,ax
   30bb5:	06                   	push   es
   30bb6:	57                   	push   di
   30bb7:	c4 3e 60 73          	les    di,DWORD PTR ds:0x7360
   30bbb:	81 c7 00 02          	add    di,0x200
   30bbf:	06                   	push   es
   30bc0:	57                   	push   di
   30bc1:	b8 00 01             	mov    ax,0x100
   30bc4:	50                   	push   ax
   30bc5:	9a af 1a c0 0c       	call   0xcc0:0x1aaf
   30bca:	81 46 f8 00 01       	add    WORD PTR [bp-0x8],0x100
   30bcf:	8b 46 f8             	mov    ax,WORD PTR [bp-0x8]
   30bd2:	c4 7e fa             	les    di,DWORD PTR [bp-0x6]
   30bd5:	03 f8                	add    di,ax
   30bd7:	06                   	push   es
   30bd8:	57                   	push   di
   30bd9:	c4 3e 60 73          	les    di,DWORD PTR ds:0x7360
   30bdd:	81 c7 00 03          	add    di,0x300
   30be1:	06                   	push   es
   30be2:	57                   	push   di
   30be3:	b8 00 01             	mov    ax,0x100
   30be6:	50                   	push   ax
   30be7:	9a af 1a c0 0c       	call   0xcc0:0x1aaf
   30bec:	ff 76 fc             	push   WORD PTR [bp-0x4]
   30bef:	ff 76 fa             	push   WORD PTR [bp-0x6]
   30bf2:	ff 76 fe             	push   WORD PTR [bp-0x2]
   30bf5:	9a 54 02 c0 0c       	call   0xcc0:0x254
   30bfa:	8a 46 06             	mov    al,BYTE PTR [bp+0x6]
   30bfd:	c4 3e 18 44          	les    di,DWORD PTR ds:0x4418
   30c01:	26 88 85 c5 00       	mov    BYTE PTR es:[di+0xc5],al
   30c06:	89 ec                	mov    sp,bp
   30c08:	5d                   	pop    bp
   30c09:	ca 02 00             	retf   0x2
   30c0c:	55                   	push   bp
   30c0d:	89 e5                	mov    bp,sp
   30c0f:	5d                   	pop    bp
   30c10:	cb                   	retf
```

### epilogue_and_following_table

```asm
   30bfa:	8a 46 06             	mov    al,BYTE PTR [bp+0x6]
   30bfd:	c4 3e 18 44          	les    di,DWORD PTR ds:0x4418
   30c01:	26 88 85 c5 00       	mov    BYTE PTR es:[di+0xc5],al
   30c06:	89 ec                	mov    sp,bp
   30c08:	5d                   	pop    bp
   30c09:	ca 02 00             	retf   0x2
   30c0c:	55                   	push   bp
   30c0d:	89 e5                	mov    bp,sp
   30c0f:	5d                   	pop    bp
   30c10:	cb                   	retf
   30c11:	0f 01 49 01          	sidtw  [bx+di+0x1]
   30c15:	4e                   	dec    si
   30c16:	01 9f 01 c5          	add    WORD PTR [bx-0x3aff],bx
   30c1a:	01 eb                	add    bx,bp
   30c1c:	01 34                	add    WORD PTR [si],si
   30c1e:	02 66 02             	add    ah,BYTE PTR [bp+0x2]
   30c21:	59                   	pop    cx
```
